//
// Created by Sherman Yan on 4/14/23.
//

#include "Track.h"

Track::Track() {

    setState(SELECTED, false);

    background = {{1530, 120},8,{36,41,46}};
    outline = {{1538, 128},10,{185,185,185}} ;

    Position::center(outline,background);

}
void Track::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    for (auto& n: audioTrack) {
        for (auto& node: n.second) {
            node->eventHandler(window,event);

            if(node->checkStates(SELECTED)&& sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                node.reset();
                n.second.erase(std::find(n.second.begin(), n.second.end(), node));
            }
        }
    }

}

void Track::update(const sf::RenderWindow &window) {

    for (auto& n: audioTrack) {
        for (auto& node: n.second) {
            node->update(window);
        }
    }

}

void Track::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();

    if(checkStates(SELECTED))
        target.draw(outline, states);

    target.draw(background,states);

    for (auto& n: audioTrack) {
        for (auto& node: n.second) {
            target.draw(*node,states);
        }
    }

}

sf::FloatRect Track::getGlobalBounds() const {
    return getTransform().transformRect(background.getGlobalBounds());
}

sf::FloatRect Track::getLocalBounds() const {
    return background.getLocalBounds();
}

void Track::setFillColor(const sf::Color &color) {
    background.setFillColor(color);
}

std::map<float, std::vector<AudioNode>> Track::getAudioTrack() {
    std::map<float, std::vector<AudioNode>> track;
    for (auto &i: audioTrack) {
        for (auto &node: i.second) {
            track[i.first].push_back(node->getNode());
        }
    }
    return track;
}


void Track::setTrackColor(const sf::Color &trackColor) {
    Track::trackColor = trackColor;
}

void Track::setChildrenTransform(const sf::Transform &transform) {
    for (auto& n: audioTrack) {
        for (auto& node: n.second) {
            node->setParentTransform(transform);
        }
    }
}



