//
// Created by Sherman Yan on 4/23/23.
//

#ifndef DIZZLESTUDIOPRO_SOUNDKEYPAIR_H
#define DIZZLESTUDIOPRO_SOUNDKEYPAIR_H
#include "SoundKeys.h"

struct SoundKeyPair{
public:
    SoundKeys keyEnum;
    unsigned int octave;

    SoundKeyPair(){
        this->keyEnum = NULL_KEY;
        this->octave = 0;
    }

    SoundKeyPair(unsigned int octave, SoundKeys keyEnum){
        this->keyEnum = keyEnum;
        this->octave = octave;

    }

    SoundKeyPair(SoundKeys keyEnum){
        this->keyEnum = keyEnum;
    }

};


#endif //DIZZLESTUDIOPRO_SOUNDKEYPAIR_H
