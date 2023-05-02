//
// Created by Sherman Yan on 4/24/23.
//

#ifndef DIZZLESTUDIOPRO_VOCALTRACK_H
#define DIZZLESTUDIOPRO_VOCALTRACK_H

#include "Track.h"

class VocalTrack: public Track {
public:
    VocalTrack();

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;
};


#endif //DIZZLESTUDIOPRO_VOCALTRACK_H
