//
// Created by Brandon Hargitay on 4/19/23.
//

#include "Application.h"
//#include "AudioVisualizer.h"
#include "AudioRecordingPanel.h"
int main(){

    Application tester;
    tester.setWindowSize({2000, 1800});
    tester.setBgColor(sf::Color::Black);
//    AudioVisualizer liveVisualizer(100,800);

    AudioRecordingPanel liveVisualizer;

//    liveVisualizer.setScale(0.9f, 0.9f);
    liveVisualizer.setPosition({20, 900});

    tester.addComponent(liveVisualizer);
    tester.run();

    return 0;
};