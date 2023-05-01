//
// Created by Brandon Hargitay on 4/30/23.
//

#ifndef DIZZLESTUDIOPRO_PLAYAUDIOMAP_H
#define DIZZLESTUDIOPRO_PLAYAUDIOMAP_H

#include <iostream>
#include <map>
#include "AudioNode.h"

class PlayAudioMap {
public:
    static void playAudioMap(const std::map<float, std::vector<AudioNode>>& audioMap);


};


#endif //DIZZLESTUDIOPRO_PLAYAUDIOMAP_H
