//
// Created by Brandon Hargitay on 4/19/23.
//
#include "Application.h"
#include "StaticAudioVisualizer.h"
#include "StaticVisualizerPanel.h"
int main(){

    Application tester;
    tester.setWindowSize({2000, 1800});
    tester.setBgColor(sf::Color::Black);
    StaticVisualizerPanel staticVisualizer;
//    StaticAudioVisualizer staticVisualizer("App/Resources/Sounds/TestSounds/Naruto.wav", {1000,400});
    staticVisualizer.setPosition({20, 900});
    //staticVisualizer.setScale(2,0.5);
    tester.addComponent(staticVisualizer);
    tester.run();

    return 0;
};