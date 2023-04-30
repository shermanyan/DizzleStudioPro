//
// Created by Sherman Yan on 4/14/23.
//

#include "Layer.h"

Layer::Layer() {
    setTrack(EMPTY);
    setState(SELECTED,false);
}

void Layer::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    if(event.type == sf::Event::KeyPressed && MouseEvents::isHover(getCombinedTransform().transformRect(label.getGlobalBounds()),window)) {
        sf::Keyboard::Key key = event.key.code;
        switch (key) {
            case sf::Keyboard::K: {
                setTrack(KEYBOARD);
                break;
            }
            case sf::Keyboard::V: {
                setTrack(VOCAL);
                break;
            }
            case sf::Keyboard::A: {
                setTrack(AUDIO);
                break;
            }
        }
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
    track->eventHandler(window, event);

//        if (instrumentPanel->getActivePanel() == label.getTrackType() && label.getTrackType() != EMPTY) {
//            bool drawNew = true;
//            if(label.getTrackType() == KEYBOARD){
//                AudioNode key = instrumentPanel->getPanel()->getKeyPressed(window);
//                AudioNode* lastKey = &track.getLastNode().getNode();
//                if (key.keyEnum != NULL_KEY && key.keyEnum == lastKey->keyEnum) {
//                    lastKey->setStopTimeStamp(seekBar->getElapsedTime());
//                    drawNew = false;
//                }
//            }
//            if(drawNew) {
//                AudioNode key = instrumentPanel->getPanel()->getKeyPressed(window);
//                if (key.keyEnum != NULL_KEY) {
//                    track.emplace_back(seekBar->getElapsedTime(), key);
//                }
//            }
//        }


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
    track->setParentTransform(getTransform());
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





