//
// Created by Sherman Yan on 4/15/23.
//
#include "Application.h"
#include "OctaveKeys.h"
#include "Keyboard.h"
#include "UIComponents/Panels/DynamicInstrumentPanel/Panels/KeyboardPanel.h"
int main(){

    Application tester;
    tester.setWindowSize({2000, 1125});
    tester.setBgColor(sf::Color{31,31,31});

    KeyboardPanel panel;
    panel.setPosition({20,700});
//    Key key;
//    key.setPosition(100,100);
//    OctaveKeys octave;
//    octave.setPosition(100,1000);
//    octave.setSize({ 200, 100 });
//
//
//    octave.getGlobalBounds();

//    Keyboard keyboard(2,{1000,500});
//    keyboard.setPosition(200,100);



//    tester.addComponent(key);
//    tester.addComponent(octave);

//    tester.addComponent(keyboard);
    tester.addComponent(panel);

    tester.run();
    return 0;
}