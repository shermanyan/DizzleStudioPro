//
// Created by Brandon Hargitay on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_SOUNDS_H
#define DIZZLESTUDIOPRO_SOUNDS_H

#include <SFML/Audio.hpp>
#include "SoundKeys.h"
#include <map>
#include "AudioNode.h"

class Sounds {
private:
    static std::map<AudioNode, sf::SoundBuffer> map;
    static void load(const AudioNode& soundPair);
    static std::string getPath(const AudioNode& soundPair);
public:
    static sf::SoundBuffer& getSound(const AudioNode& soundPair);
};


#endif //DIZZLESTUDIOPRO_SOUNDS_H
