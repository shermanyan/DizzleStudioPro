//
// Created by Sherman Yan on 4/24/23.
//

#ifndef DIZZLESTUDIOPRO_DRUMPADTRACK_H
#define DIZZLESTUDIOPRO_DRUMPADTRACK_H

#include "Track.h"

class DrumPadTrack: public Track {

public:
    DrumPadTrack();

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;
};




#endif //DIZZLESTUDIOPRO_DRUMPADTRACK_H
