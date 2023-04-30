//
// Created by Sherman Yan on 4/23/23.
//

#ifndef DIZZLESTUDIOPRO_AUDIONODE_H
#define DIZZLESTUDIOPRO_AUDIONODE_H
#include "SoundKeys.h"
#include "States.h"

struct AudioNode: public States{
private:

    void setDuration(){
        switch (keyEnum) {
            case DRUM:
                duration = 2;
            default:
                duration = 0;
        }
    }

public:
    SoundKeys keyEnum = NULL_KEY;
    unsigned int octave = 0;

    float duration = 0, timeStamp = 0;

    AudioNode(){
        this->keyEnum = NULL_KEY;
        this->octave = 0;
    }

    AudioNode(unsigned int octave, SoundKeys keyEnum){
        this->keyEnum = keyEnum;
        this->octave = octave;
        setDuration();
    }

    AudioNode(SoundKeys keyEnum){
        this->keyEnum = keyEnum;
        setDuration();
    }

    void setStopTimeStamp(float time){
        duration = time - timeStamp;
    }

    bool operator<(const AudioNode& other) const {
        if (keyEnum == other.keyEnum) {
            return octave < other.octave;
        }
        return keyEnum < other.keyEnum;
    }
};


#endif //DIZZLESTUDIOPRO_AUDIONODE_H
