//
// Created by Sherman Yan on 4/24/23.
//

#include "DrawableAudioNode.h"
#include <iostream>

float DrawableAudioNode::scale;

void DrawableAudioNode::setDuration(int duration) {
    DrawableAudioNode::scale = 1510.f/duration;
}

void DrawableAudioNode::positionNode() {

    switch (node.keyEnum) {
        case NULL_KEY:
        case DRUM:
            box.setPosition(node.timeStamp*DrawableAudioNode::scale, trackHeight);
            break;
        case C: {
            box.setPosition(node.timeStamp*DrawableAudioNode::scale,box.getSize().y);
            break;
        }
        case D: {
            box.setPosition(node.timeStamp*DrawableAudioNode::scale,box.getSize().y*3);
            break;
        }
        case E: {
            box.setPosition(node.timeStamp*DrawableAudioNode::scale,box.getSize().y*5);
            break;
        }
        case F: {
            box.setPosition(node.timeStamp*DrawableAudioNode::scale,box.getSize().y*6);
            break;
        }
        case G: {
            box.setPosition(node.timeStamp*DrawableAudioNode::scale,box.getSize().y*8);
            break;
        }
        case A: {
            box.setPosition(node.timeStamp*DrawableAudioNode::scale,box.getSize().y*10);
            break;
        }
        case B: {
            box.setPosition(node.timeStamp*DrawableAudioNode::scale,box.getSize().y*12);
            break;
        }
        case Cs: {
            box.setPosition(node.timeStamp*DrawableAudioNode::scale,box.getSize().y*2);
            break;
        }
        case Ds: {
            box.setPosition(node.timeStamp*DrawableAudioNode::scale,box.getSize().y*4);
            break;
        }
        case Fs: {
            box.setPosition(node.timeStamp*DrawableAudioNode::scale,box.getSize().y*7);
            break;
        }
        case Gs: {
            box.setPosition(node.timeStamp*DrawableAudioNode::scale,box.getSize().y*9);
            break;
        }
        case As: {
            box.setPosition(node.timeStamp*DrawableAudioNode::scale,box.getSize().y*11);
            break;
        }
    }

}

void DrawableAudioNode::setSize() {
    switch (node.keyEnum) {
        case NULL_KEY:
        case DRUM:
            throw;
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
    }
    box.setOrigin(0,box.getSize().y);
}

DrawableAudioNode::DrawableAudioNode(float timeStamp, AudioNode key, const sf::Color& color, float trackHeight) {
    this->trackHeight = trackHeight;
    node = key;
    node.timeStamp = timeStamp;
    box.setFillColor(sf::Color((int)(rand() % 255 + 1) ,(int)(rand() % 255 + 1),(int)(rand() % 255 + 1)));
}

AudioNode& DrawableAudioNode::getNode() {
    return node;
}

void DrawableAudioNode::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
}

void DrawableAudioNode::update(const sf::RenderWindow &window) {
    setSize();
    positionNode();
}

void DrawableAudioNode::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(box,states);
}

