//
// Created by Sherman Yan on 4/21/23.
//

#ifndef DIZZLESTUDIOPRO_SOUNDKEYS_H
#define DIZZLESTUDIOPRO_SOUNDKEYS_H
#include <string>

enum SoundKeys{
    NULL_KEY,
    C,D,E,F,G,A,B,
    Cs,Ds,Fs,Gs,As,
    DRUM, SOUND, CLAP,
    SNARE, KICK, HIGHTOM,
    HIGHHAT, BASS, Cymbal

};

static const std::string SoundKeysStrings[] = {
        "NULL_KEY","C", "D", "E", "F",
        "G", "A","B", "Cs", "Ds", "Fs",
        "Gs", "As","Drum","Sound", "Clap", "Snare",
        "Kick", "High Tom", "High Hat", "Bass",
        "Cymbal"
};

#endif //DIZZLESTUDIOPRO_SOUNDKEYS_H
