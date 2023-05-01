//
// Created by Sherman Yan on 4/24/23.
//

#include "DrumPadTrack.h"

DrumPadTrack::DrumPadTrack() : Track{}{
//    setFillColor(sf::Color::Green);
}

void DrumPadTrack::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    Track::eventHandler(window, event);

    if (event.type == sf::Event::MouseButtonPressed && checkStates(SELECTED) && checkStates(RECORDING)) {
        std::vector<AudioNode *> nodesPressed = dynamic_cast<DrumPadPanel*>(StudioStatics::panel->getPanel())->getKeyPressed(window);
        for (auto &n: nodesPressed) {
            float timeStamp = StudioStatics::seekBar->getElapsedTime();
            audioTrack[timeStamp].emplace_back(std::make_unique<DrawableAudioNode>(timeStamp, *n, trackColor));
        }
    }
}
