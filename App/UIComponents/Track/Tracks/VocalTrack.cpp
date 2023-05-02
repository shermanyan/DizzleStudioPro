//
// Created by Sherman Yan on 4/24/23.
//

#include "VocalTrack.h"

VocalTrack::VocalTrack(): Track{}{
//    setFillColor(sf::Color::Blue);
}

void VocalTrack::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    Track::eventHandler(window, event);
    auto* panel = dynamic_cast<AudioRecordingPanel*>(StudioStatics::panel->getPanel());
    if (event.type == sf::Event::MouseButtonPressed && checkStates(SELECTED)&& panel->getStatus(window)){
        float timeStamp = StudioStatics::seekBar->getElapsedTime().asSeconds();
        audioTrack[timeStamp].emplace_back(std::make_unique<DrawableAudioNode>(timeStamp, *panel->getNode(), trackColor));
        audioTrack[timeStamp].back()->setParentTransform(getCombinedTransform());
    }
}
