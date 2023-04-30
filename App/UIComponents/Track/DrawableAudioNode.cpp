//
// Created by Sherman Yan on 4/24/23.
//

#include "DrawableAudioNode.h"
#include <iostream>

float DrawableAudioNode::scale;

void DrawableAudioNode::setDurationScale(int duration) {
    DrawableAudioNode::scale = 1510.f/duration;
}

void DrawableAudioNode::positionNode() {
    box.setPosition(node.timeStamp*DrawableAudioNode::scale, 0);
    setSize();

    switch (node.keyEnum) {
        case NULL_KEY:
        case DRUM:
            box.setPosition(box.getPosition() + sf::Vector2f{0, trackHeight});
            break;
        case C: {
            box.setPosition(box.getPosition() + sf::Vector2f {0,box.getSize().y});
            break;
        }
        case D: {
            box.setPosition(box.getPosition() + sf::Vector2f {0,box.getSize().y*3});
            break;
        }
        case E: {
            box.setPosition(box.getPosition() + sf::Vector2f {0,box.getSize().y*5});
            break;
        }
        case F: {
            box.setPosition(box.getPosition() + sf::Vector2f {0,box.getSize().y*6});
            break;
        }
        case G: {
            box.setPosition(box.getPosition() + sf::Vector2f {0,box.getSize().y*8});
            break;
        }
        case A: {
            box.setPosition(box.getPosition() + sf::Vector2f {0,box.getSize().y*10});
            break;
        }
        case B: {
            box.setPosition(box.getPosition() + sf::Vector2f {0,box.getSize().y*12});
            break;
        }
        case Cs: {
            box.setPosition(box.getPosition() + sf::Vector2f {0,box.getSize().y*2});
            break;
        }
        case Ds: {
            box.setPosition(box.getPosition() + sf::Vector2f {0,box.getSize().y*4});
            break;
        }
        case Fs: {
            box.setPosition(box.getPosition() + sf::Vector2f {0,box.getSize().y*7});
            break;
        }
        case Gs: {
            box.setPosition(box.getPosition() + sf::Vector2f {0,box.getSize().y*9});
            break;
        }
        case As: {
            box.setPosition(box.getPosition() + sf::Vector2f {0,box.getSize().y*11});
            break;
        }
    }

}

void DrawableAudioNode::setSize() {
    switch (node.keyEnum) {
        case C:
        case D:
        case E:
        case F:
        case G:
        case A:
        case B:
        case Cs:
        case Ds:
        case Fs:
        case Gs:
        case As:
            box.setSize({node.duration*DrawableAudioNode::scale,trackHeight/12});
            break;
        default:
            throw;

    }
    box.setOrigin(0,box.getSize().y);
}

DrawableAudioNode::DrawableAudioNode(float timeStamp, const AudioNode& key, const sf::Color& color, float trackHeight) {
    AppComponent::setState(ACTIVE, true);

    this->trackHeight = trackHeight;
    node = key;
    node.timeStamp = timeStamp;
//    box.setFillColor(sf::Color((int)(rand() % 255 + 1) ,(int)(rand() % 255 + 1),(int)(rand() % 255 + 1)));
    box.setFillColor(color);
    positionNode();
}


void DrawableAudioNode::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
}

void DrawableAudioNode::update(const sf::RenderWindow &window) {
    if(AppComponent::checkStates(ACTIVE)) {
        node.setStopTimeStamp(StudioStatics::seekBar->getElapsedTime());
    }
    positionNode();
    setSize();
}

void DrawableAudioNode::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(box,states);
}

AudioNode DrawableAudioNode::getNode() const {
    return node;
}

