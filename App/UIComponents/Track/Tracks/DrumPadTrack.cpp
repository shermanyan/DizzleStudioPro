//
// Created by Sherman Yan on 4/24/23.
//

#include "DrumPadTrack.h"

DrumPadTrack::DrumPadTrack() : Track{}{
//    setFillColor(sf::Color::Green);
}

void DrumPadTrack::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    Track::eventHandler(window, event);
}
