//
// Created by Sherman Yan on 4/14/23.
//

#include "Layer.h"

Layer::Layer() {
    setTrack(EMPTY);
    setState(SELECTED,false);

    dropDownMenu.setWidth(label.getGlobalBounds().width);
    Position::center(dropDownMenu,label);
    Position::bottom(dropDownMenu,label);
//    dropDownMenu.setState(HIDDEN, false);
}

void Layer::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    if(event.type == sf::Event::MouseButtonPressed && MouseEvents::isClick(getCombinedTransform().transformRect(label.getGlobalBounds()),window)) {
        dropDownMenu.toggleState(HIDDEN);
    }

    if (!checkStates(SELECTED)&&event.type == sf::Event::MouseButtonPressed &&
            MouseEvents::isClick(getCombinedTransform().transformRect(track->getGlobalBounds()), window)) {
        StudioStatics::panel->setActivePanel(label.getTrackType());
        setState(SELECTED, true);
        track->setState(SELECTED, true);
    }
    if(!checkStates(SELECTED))
        track->setState(SELECTED, false);

    label.eventHandler(window, event);

    track->setState(RECORDING, checkStates(RECORDING));
    track->eventHandler(window, event);

}

void Layer::update(const sf::RenderWindow &window) {
    if(checkStates(SELECTED)) {
        label.update(window);
        track->update(window);
    }

}

void Layer::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    states.transform *= getTransform();
    target.draw(label,states);
    target.draw(*track,states);

    target.draw(dropDownMenu,states);

}

void Layer::setChildrenTransform(const sf::Transform &transform) {
    label.setParentTransform(transform);
    track->setParentTransform(transform);
}

void Layer::setTrackColor(const sf::Color &color) {
    label.setTrackColor(color);
}

void Layer::setTrack(InstrumentsEnum type) {
    label.setTrack(type);

    switch (type) {
        case EMPTY: {
            track = std::make_unique<Track>();
            break;
        }
        case KEYBOARD:{
            track = std::make_unique<KeyboardTrack>();
            break;
        }
        case DRUMPAD: {
            track = std::make_unique<DrumPadTrack>();
            break;
        }
        case AUDIO: {
            track = std::make_unique<AudioTrack>();
            break;
        }
        case VOCAL: {
            track = std::make_unique<VocalTrack>();
        }


    }

    track->setTrackColor(label.getTrackColor());
//    track->setParentTransform(getCombinedTransform());
    Position::right(*track,label,10);
}

sf::FloatRect Layer::getGlobalBounds() const {
    sf::FloatRect bounds = label.getGlobalBounds();
    bounds.width += 10 + track->getGlobalBounds().width;

    return getTransform().transformRect(bounds);
}

sf::FloatRect Layer::getLocalBounds() const {
    return label.getLocalBounds();
}

InstrumentsEnum Layer::getTrackType() const {
    return label.getTrackType();
}

std::map<float, std::vector<AudioNode>> Layer::getAudioTrack() {
    return track->getAudioTrack();
}





