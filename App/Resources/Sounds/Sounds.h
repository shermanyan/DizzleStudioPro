//
// Created by Brandon Hargitay on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_SOUNDS_H
#define DIZZLESTUDIOPRO_SOUNDS_H

#include <SFML/Audio.hpp>
#include "SoundKeys.h"
#include <map>
#include "SoundKeyPair.h"

class Sounds {
private:
    static std::map<SoundKeyPair, sf::SoundBuffer> map;
    static void load(const SoundKeyPair& soundPair);
    static std::string getPath(const SoundKeyPair& soundPair);
public:
    static sf::SoundBuffer& getSound(const SoundKeyPair& soundPair);
};


#endif //DIZZLESTUDIOPRO_SOUNDS_H
