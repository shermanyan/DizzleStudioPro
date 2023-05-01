//
// Created by Brandon Hargitay on 4/30/23.
//

#ifndef DIZZLESTUDIOPRO_GETBUFFER_H
#define DIZZLESTUDIOPRO_GETBUFFER_H

#include <iostream>
#include <map>
#include "AudioNode.h"
#include <algorithm>
#include <cmath>

class GetBuffer : public States {
public:
    static sf::SoundBuffer getCombinedSoundBuffer(const std::map<float, std::vector<AudioNode>>& audioMap, unsigned int targetSampleRate);

private:
    static sf::SoundBuffer convertToMono(const sf::SoundBuffer &buffer);
    static sf::SoundBuffer resampleSoundBuffer(const sf::SoundBuffer &buffer, unsigned int targetSampleRate);

    };


#endif //DIZZLESTUDIOPRO_GETBUFFER_H
