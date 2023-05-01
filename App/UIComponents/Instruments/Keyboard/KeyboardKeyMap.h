//
// Created by Sherman Yan on 4/30/23.
//

#ifndef DIZZLESTUDIOPRO_KEYBOARDKEYMAP_H
#define DIZZLESTUDIOPRO_KEYBOARDKEYMAP_H
#include "SoundKeys.h"
#include <SFML/Graphics.hpp>

class KeyboardKeyMap {

public:
    static bool isKeyBoardPress(SoundKeys keyEnum, unsigned int octave = 0);


};


#endif //DIZZLESTUDIOPRO_KEYBOARDKEYMAP_H
