//
// Created by Brandon Hargitay on 4/19/23.
//

#include <iostream>
#include "AudioRecordingPanel.h"
#include "Textures.h"
#include "MouseEvents.h"

AudioRecordingPanel::AudioRecordingPanel() : liveRecording(100,2200){
    texture = Textures::getTexture(MIC_BUTTON_RED);
    button.setTexture(texture);
    button.setSize({200,200});
}

void AudioRecordingPanel::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    DynamicInstrumentPanel::eventHandler(window, event);

    if(MouseEvents::isClick(button.getGlobalBounds(),window) ){
        if(!isRecording){
            button.setTexture(Textures::getTexture(PAUSE_BUTTON_RED));
            liveRecording.startRecording();
            isRecording = true;
            return;
        }else if (isRecording){
            button.setTexture(Textures::getTexture(PLAY_BUTTON_GREY));
//            liveRecording.stop();
            isRecording = false;
        }
        if(!isRecording){
            std::cout << "Test";
            liveRecording.stopRecording();
        }
    }
}

void AudioRecordingPanel::update(const sf::RenderWindow &window) {
    DynamicInstrumentPanel::update(window);
}

void AudioRecordingPanel::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    DynamicInstrumentPanel::draw(target, states);
    liveRecording.draw(target,states);
    target.draw(button);

}

void AudioRecordingPanel::setPosition(sf::Vector2f pos) {
    DynamicInstrumentPanel::setPosition(pos);
    pos.x = DynamicInstrumentPanel::getGlobalBounds().left + 880;
    pos.y = DynamicInstrumentPanel::getGlobalBounds().top + 905;
    button.setPosition(sf::Vector2f(DynamicInstrumentPanel::getGlobalBounds().left + 500 , DynamicInstrumentPanel::getGlobalBounds().top +100));

    liveRecording.setPosition(pos);
}

void AudioRecordingPanel::setScale(float x, float y) {
    liveRecording.setScale(x,y);
}






