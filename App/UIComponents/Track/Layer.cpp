//
// Created by Sherman Yan on 4/14/23.
//

#include "Layer.h"

DynamicInstrumentPanel* Layer::instrumentPanel = nullptr;
SeekBar* Layer::seekBar = nullptr;

Layer::Layer() {
    setTrack(EMPTY);
    setState(SELECTED,false);
    Position::right(track,label,10);
}

void Layer::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed &&
            MouseEvents::isClick(getCombinedTransform().transformRect(track.getGlobalBounds()), window)) {
        instrumentPanel->setActivePanel(label.getTrackType());
        setState(SELECTED, true);
        track.setState(SELECTED, true);
    } else if(instrumentPanel->getActivePanel() != label.getTrackType()) {
        setState(SELECTED, false);
        track.setState(SELECTED, false);
    }


    if (checkStates(SELECTED)) {
        label.eventHandler(window, event);
        track.eventHandler(window, event);

        if (instrumentPanel->getActivePanel() == label.getTrackType() && label.getTrackType() != EMPTY) {
            bool drawNew = true;
            if(label.getTrackType() == KEYBOARD && event.type != event.MouseButtonReleased){
                AudioNode key = instrumentPanel->getPanel()->getKeyPressed(window);
                AudioNode* lastKey = &track.getLastNode().getNode();
                if (key.keyEnum != NULL_KEY && key.keyEnum == lastKey->keyEnum) {
                    lastKey->setStopTimeStamp(seekBar->getElapsedTime());
                    drawNew = false;
                }
            }
            if(drawNew) {
                AudioNode key = instrumentPanel->getPanel()->getKeyPressed(window);
                if (key.keyEnum != NULL_KEY) {
                    track.emplace_back(seekBar->getElapsedTime(), key);
                }
            }
        }

    }

}

void Layer::update(const sf::RenderWindow &window) {
    if(checkStates(SELECTED)) {
        label.update(window);
    }

    track.update(window);
}

void Layer::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    states.transform *= getTransform();
    target.draw(label,states);
    target.draw(track,states);

}

void Layer::setChildrenTransform(const sf::Transform &transform) {
    label.setParentTransform(transform);
    track.setParentTransform(transform);
}

void Layer::setTrackColor(const sf::Color &color) {
    label.setTrackColor(color);
    track.setTrackColor(color);
}

void Layer::setTrack(InstrumentsEnum type) {
    label.setTrack(type);
}

sf::FloatRect Layer::getGlobalBounds() const {
    sf::FloatRect bounds = label.getGlobalBounds();
    bounds.width += 10 + track.getGlobalBounds().width;

    return getTransform().transformRect(bounds);
}

sf::FloatRect Layer::getLocalBounds() const {
    return label.getLocalBounds();
}

InstrumentsEnum Layer::getTrackType() const {
    return label.getTrackType();
}

void Layer::setInstrumentPanel(DynamicInstrumentPanel *instrumentPanel) {
    Layer::instrumentPanel = instrumentPanel;
}

void Layer::setSeekBar(SeekBar *seekbar) {
    Layer::seekBar = seekbar;
}



