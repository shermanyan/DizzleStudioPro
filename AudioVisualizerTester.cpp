//
// Created by Brandon Hargitay on 4/19/23.
//
#include "Application.h"
#include "StaticAudioVisualizer.h"

int main(){

    Application tester;
    tester.setWindowSize({3500, 2000});
    tester.setBgColor(sf::Color::Black);

    StaticAudioVisualizer staticVisualizer("App/Resources/Sounds/TestSounds/Naruto.wav", tester.getSize().x, tester.getSize().y);

    tester.addComponent(staticVisualizer);

    tester.run();

    return 0;
};