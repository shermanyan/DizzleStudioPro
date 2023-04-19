//
// Created by Brandon Hargitay on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_SOUNDS_H
#define DIZZLESTUDIOPRO_SOUNDS_H

#include <SFML/Audio.hpp>
#include "SoundsEnum.h"
#include <map>

class Sounds {

private:
    static std::map<SoundsEnum, sf::SoundBuffer> map;
    static void load(SoundsEnum texture);
    static std::string getPath(SoundsEnum texture);
public:
    static sf::SoundBuffer& getSound(SoundsEnum texture);

};


#endif //DIZZLESTUDIOPRO_SOUNDS_H
