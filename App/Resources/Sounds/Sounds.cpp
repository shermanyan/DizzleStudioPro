#include "Sounds.h"

std::map<SoundKeys, sf::SoundBuffer> Sounds::map;

void Sounds::load(const AudioNode& soundPair) {
    if (map.count(soundPair.keyEnum) == 0 && !map[soundPair.keyEnum].loadFromFile(getPath(soundPair)))
        exit(20);
}

std::string Sounds::getPath(const AudioNode& soundPair) {
    std::string basePath = "App/Resources/Sounds/KeyBoardNotes/";
    std::string fileName = SoundKeysStrings[soundPair.keyEnum] + std::to_string(soundPair.octave) + ".wav";
    return basePath + fileName;
}

sf::SoundBuffer &Sounds::getSound(const AudioNode& soundPair) {
    if (map.count(soundPair.keyEnum) == 0)
        load(soundPair);
    return map.at(soundPair.keyEnum);
}
