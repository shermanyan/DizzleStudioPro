//
// Created by Sherman Yan on 4/15/23.
//
#include "Application.h"
#include "OctaveKeys.h"
#include "Keyboard.h"
#include <iostream>
int main(){

//    Key key;
//    key.setPosition(100,100);
    OctaveKeys octave;
    octave.setPosition(100,500);
    octave.setFillColors({{36,36,36},{94,94,94}});
//
//
//    octave.getGlobalBounds();
//    Keyboard keyboard;
//    keyboard.setPosition(100,100);

    ScrollableContainer<OctaveKeys> keys;
    for (int i = 0; i < 2 ; ++i) {
        keys.push_back({});
    }
    keys.setPosition(100,100);

    Application tester;
    tester.setBgColor(sf::Color{31,31,31});

//    tester.addComponent(key);
    tester.addComponent(octave);
    tester.addComponent(keys);

//    tester.addComponent(keyboard);
    tester.run();
    return 0;
}