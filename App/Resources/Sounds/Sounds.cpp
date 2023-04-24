#include "Sounds.h"

std::map<SoundKeyPair, sf::SoundBuffer> Sounds::map;

void Sounds::load(const SoundKeyPair& soundPair) {
    if (map.count(soundPair) == 0 && !map[soundPair].loadFromFile(getPath(soundPair)))
        exit(20);
}

std::string Sounds::getPath(const SoundKeyPair& soundPair) {
    std::string basePath = "App/Resources/Sounds/KeyBoardNotes/";
    std::string fileName = SoundKeysStrings[soundPair.keyEnum] + std::to_string(soundPair.octave) + ".wav";
    return basePath + fileName;
}

sf::SoundBuffer &Sounds::getSound(const SoundKeyPair& soundPair) {
    if (map.count(soundPair) == 0)
        load(soundPair);
    return map.at(soundPair);
}
