//
// Created by Sherman Yan on 4/15/23.
//
#include "Application.h"
#include "OctaveKeys.h"
#include "Keyboard.h"
int main(){

    Application tester;
    tester.setWindowSize({3500, 2000});
    tester.setBgColor(sf::Color{31,31,31});

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

    ScrollableContainer<Keyboard> keys;
    for (int i = 0; i < 3 ; ++i) {
        keys.push_back({});
//        keys.begin()->push_back({});
    }

    keys.setScrollDirection(HORIZONTAL);


    std::cout << (float)tester.getSize().x;
    keys.setPosition(100,600);
    keys.setBound(sf::FloatRect{100,0,10,10});

//    tester.addComponent(key);
//    tester.addComponent(octave);
    tester.addComponent(keys);

    tester.addComponent(keyboard);
    tester.run();
    return 0;
}