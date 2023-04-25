//
// Created by Brandon Hargitay on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_SOUNDS_H
#define DIZZLESTUDIOPRO_SOUNDS_H

#include <SFML/Audio.hpp>
#include "SoundKeys.h"
#include <map>

class Sounds {

private:
    static std::map<SoundKeys, sf::SoundBuffer> map;
    static void load(SoundKeys texture);
    static std::string getPath(SoundKeys texture);
public:
    static sf::SoundBuffer& getSound(SoundKeys texture);

};


#endif //DIZZLESTUDIOPRO_SOUNDS_H
