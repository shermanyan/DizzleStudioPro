//
// Created by Sherman Yan on 4/23/23.
//

#ifndef DIZZLESTUDIOPRO_AUDIOTRACK_H
#define DIZZLESTUDIOPRO_AUDIOTRACK_H

#include "Track.h"

class AudioTrack: public Track {

public:
    AudioTrack();

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;
};



#endif //DIZZLESTUDIOPRO_AUDIOTRACK_H
