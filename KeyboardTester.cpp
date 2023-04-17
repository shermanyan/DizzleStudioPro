//
// Created by Sherman Yan on 4/15/23.
//
#include "Application.h"
#include "OctaveKeys.h"
#include "Keyboard.h"
int main(){

//    Key key;
//    key.setPosition(100,100);
//    OctaveKeys octave;
//    octave.setPosition(100,1000);
//    octave.setFillColors({{36,36,36},{94,94,94}});
//
//
//    octave.getGlobalBounds();
    Keyboard keyboard;
    keyboard.setPosition(200,100);

    ScrollableContainer<Key> keys;
    for (int i = 0; i < 3 ; ++i) {
        keys.push_back({{100, 100}, sf::Color::White});
    }

    keys.setPosition(100,600);

    Application tester;
    tester.setWindowSize({3500, 2000});
    tester.setBgColor(sf::Color{31,31,31});

//    tester.addComponent(key);
//    tester.addComponent(octave);
    tester.addComponent(keys);

    tester.addComponent(keyboard);
    tester.run();
    return 0;
}