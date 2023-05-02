//
// Created by Sherman Yan on 4/23/23.
//

#include "AudioTrack.h"

AudioTrack::AudioTrack() : Track{}{
//    setFillColor(sf::Color::Yellow);
}

void AudioTrack::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    Track::eventHandler(window, event);
    auto* panel = dynamic_cast<StaticVisualizerPanel*>(StudioStatics::panel->getPanel());
    if (checkStates(SELECTED)&& panel->getStatus(window)){
        float timeStamp = StudioStatics::seekBar->getElapsedTime().asSeconds();
        audioTrack[timeStamp].emplace_back(std::make_unique<DrawableAudioNode>(timeStamp, *panel->getNode(), trackColor));
        audioTrack[timeStamp].back()->setParentTransform(getCombinedTransform());
    }
}

