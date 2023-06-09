//
// Created by Sherman Yan on 4/24/23.
//

#include "DrawableAudioNode.h"
#include <iostream>

float DrawableAudioNode::scale;

void DrawableAudioNode::setDurationScale(int duration) {
    DrawableAudioNode::scale = 1530.f/duration;
}

void DrawableAudioNode::positionNode() {
    box.setPosition(node.timeStamp*DrawableAudioNode::scale, 0);
    setSize();

    switch (node.keyEnum) {
        case NULL_KEY:
            throw;
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
        default:
            box.setPosition(box.getPosition() + sf::Vector2f{0, trackHeight});
            break;

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
            float d = node.duration*DrawableAudioNode::scale;
            if ((node.duration  + node.timeStamp) >StudioStatics::seekBar->getDuration()) {
                d = (StudioStatics::seekBar->getDuration() - node.timeStamp);
                box.setSize({d*DrawableAudioNode::scale,trackHeight*0.6f});
            } else
                box.setSize({d,trackHeight*0.6f});

            box.setRadius({5,5,0,0});
            break;

    }
    box.setOrigin(0,box.getSize().y);
}

DrawableAudioNode::DrawableAudioNode(float timeStamp, const AudioNode& key, const sf::Color& color, float trackHeight) {
    AppComponent::setState(ACTIVE, false);

    this->trackHeight = trackHeight;
    node = key;
    node.timeStamp = timeStamp;
    this->color = color;
    box.setFillColor(color);
    positionNode();
    setSize();
}


void DrawableAudioNode::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed && MouseEvents::isClick(getCombinedTransform().transformRect(box.getGlobalBounds()),window)){
        toggleState(SELECTED);
        box.setFillColor( color + sf::Color{50,50,50});
    } else if(!checkStates(SELECTED))
        box.setFillColor(color);

}

void DrawableAudioNode::update(const sf::RenderWindow &window) {
    if(AppComponent::checkStates(ACTIVE)) {
        node.setStopTimeStamp(StudioStatics::seekBar->getElapsedTime().asSeconds());
    }
    setSize();
    positionNode();
}

void DrawableAudioNode::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(box,states);
}

AudioNode DrawableAudioNode::getNode() const {
    return node;
}

