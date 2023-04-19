//
// Created by Brandon Hargitay on 4/19/23.
//

#include "Sounds.h"

std::map<SoundsEnum, sf::SoundBuffer> Sounds::map;

void Sounds::load(SoundsEnum sound) {
    if (map.count(sound) == 0 &&!map[sound].loadFromFile(getPath(sound)))
        exit(20);
}

std::string Sounds::getPath(SoundsEnum texture) {
    switch (texture){
        case NARUTO:
            return "App/Resources/Sounds/TestSounds/Naruto.wav";
        case LAST_IMG:
            break;
    }
}

sf::SoundBuffer &Sounds::getSound(SoundsEnum sound) {
    if (map.count(sound) == 0)
        load(sound);
    return map.at(sound);
}

