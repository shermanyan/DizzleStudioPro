//
// Created by Brandon Hargitay on 4/19/23.
//

#include "SoundKeys.h"
#include "Sounds.h"

std::map<SoundKeys, sf::SoundBuffer> Sounds::map;

void Sounds::load(SoundKeys sound) {
    if (map.count(sound) == 0 &&!map[sound].loadFromFile(getPath(sound)))
        exit(20);
}

std::string Sounds::getPath(SoundKeys sound) {
    switch (sound){
        case A:
            return "";
        case C:
            break;
        case D:
            break;
        case E:
            break;
        case F:
            break;
        case G:
            break;
        case B:
            break;
        case Cs:
            break;
        case Ds:
            break;
        case Fs:
            break;
        case Gs:
            break;
        case As:
            break;
        case NULL_KEY:
            break;
    }
}

sf::SoundBuffer &Sounds::getSound(SoundKeys sound) {
    if (map.count(sound) == 0)
        load(sound);
    return map.at(sound);
}

