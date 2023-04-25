//
// Created by Sherman Yan on 4/14/23.
//

#include "Track.h"
#include <iostream>

Track::Track() {

    setState(SELECTED, false);

    background = {{1520, 110},8,{36,41,46}};
    outline = {{1530, 120},10} ;

    Position::center(background,outline);

}
void Track::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
}

void Track::update(const sf::RenderWindow &window) {
//    std::cout << audioTrack.size() << " ";
    if(checkStates(SELECTED))
        outline.setFillColor({185,185,185});
    else
        outline.setFillColor({36,41,46});

    for (auto& n: audioTrack) {
        n.second.update(window);
    }

}

void Track::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();

    target.draw(outline, states);
    target.draw(background,states);

    for (auto& n: audioTrack) {
        target.draw(n.second,states);
    }
}

sf::FloatRect Track::getGlobalBounds() const {
    return getTransform().transformRect(outline.getGlobalBounds());
}

sf::FloatRect Track::getLocalBounds() const {
    return background.getLocalBounds();
}

void Track::setFillColor(const sf::Color &color) {
    background.setFillColor(color);
}

std::map<float, AudioNode> Track::getAudioTrack() {
    std::map<float, AudioNode> track;
    for (auto &i: audioTrack)
        track[i.first] = i.second.getNode();

    return track;
}

DrawableAudioNode& Track::getLastNode() {
    return std::prev(audioTrack.end())->second;
}

void Track::emplace_back(float timeStamp, AudioNode key) {
    audioTrack.emplace(timeStamp,DrawableAudioNode{timeStamp,key, trackColor});
}

void Track::setTrackColor(const sf::Color &trackColor) {
    Track::trackColor = trackColor;
}



