//
// Created by Brandon Hargitay on 4/19/23.
//

#include "Sounds.h"

std::map<SoundKeys, sf::SoundBuffer> Sounds::map;

void Sounds::load(SoundKeys sound) {
    if (map.count(sound) == 0 &&!map[sound].loadFromFile(getPath(sound)))
        exit(20);
}

std::string Sounds::getPath(SoundKeys sound) {
    switch (sound){
        case A:
            return "App/Resources/Sounds/KeyBoardNotes/A3.wav";
        case C:
            return "";
        case D:
            return "";
        case E:
            return "";
        case F:
            return "";
        case G:
            return "";
        case B:
            return "";
        case Cs:
            return "";
        case Ds:
            return "";
        case Fs:
            return "";
        case Gs:
            return "";
        case As:
            return "";
        case NULL_KEY:
            break;
    }
}

sf::SoundBuffer &Sounds::getSound(SoundKeys sound) {
    if (map.count(sound) == 0)
        load(sound);
    return map.at(sound);
}

