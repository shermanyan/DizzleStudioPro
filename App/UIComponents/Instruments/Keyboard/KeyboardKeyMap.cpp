//
// Created by Sherman Yan on 4/30/23.
//

#include "KeyboardKeyMap.h"
#include <iostream>

bool KeyboardKeyMap::isKeyBoardPress(SoundKeys keyEnum, unsigned int octave)
{
    switch (keyEnum) {
        case NULL_KEY:
            break;
        case C:{
            switch (octave) {
                case 3:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
                case 4:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::V);
            }
        }
        case D:{
            switch (octave) {
                case 3:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::W);
                case 4:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::B);
            }
        }
        case E:{
            switch (octave) {
                case 3:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::E);
                case 4:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::N);
            }
        }
        case F:{
            switch (octave) {
                case 3:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::R);
                case 4:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::M);
            }
        }
        case G:{
            switch (octave) {
                case 3:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::T);
                case 4:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::Comma);
            }
        }
        case A:{
            switch (octave) {
                case 3:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::Y);
                case 4:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::Period);
            }
        }
        case B:{
            switch (octave) {
                case 3:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::U);
                case 4:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::Slash);
            }
        }
        case Cs:{
            switch (octave) {
                case 3:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::Num2);
                case 4:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::G);
            }
        }
        case Ds:{
            switch (octave) {
                case 3:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::Num3);
                case 4:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::H);
            }
        }
        case Fs:{
            switch (octave) {
                case 3:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::Num5);
                case 4:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::K);
            }
        }
        case Gs:{
            switch (octave) {
                case 3:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::Num6);
                case 4:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::L);
            }
        }
        case As:{
            switch (octave) {
                case 3:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::Num7);
                case 4:
                    return sf::Keyboard::isKeyPressed(sf::Keyboard::SemiColon);
            }
        }
        case DRUM:
            break;
        case SOUND:
            break;
    }
    return false;
}
