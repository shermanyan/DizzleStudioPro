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

    Position::center(button,*this);
    button.setPosition(button.getPosition().x - 600 ,button.getPosition().y);

    Position::center(liveRecording,*this);
    liveRecording.setPosition(liveRecording.getPosition().x - 200 ,liveRecording.getPosition().y);

}

void AudioRecordingPanel::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    BasePanel::eventHandler(window, event);

    if(MouseEvents::isClick(getCombinedTransform().transformRect(button.getGlobalBounds()),window) ){
        handleButtonClick();
    }
}

void AudioRecordingPanel::update(const sf::RenderWindow &window) {
    BasePanel::update(window);
}

void AudioRecordingPanel::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    BasePanel::draw(target, states);
    states.transform *= getTransform();

    target.draw(liveRecording,states);
    target.draw(button,states);

}


void AudioRecordingPanel::setChildrenTransform(const sf::Transform &transform) {
    liveRecording.setParentTransform(transform);
}

void AudioRecordingPanel::handleButtonClick() {
    if (!isRecording && !isPlaying) {
        button.setTexture(Textures::getTexture(PAUSE_BUTTON_RED));
        liveRecording.startRecording();
        isRecording = true;
    } else if (isRecording) {
        button.setTexture(Textures::getTexture(PLAY_BUTTON_GREY));
        liveRecording.stopRecording();
        isRecording = false;
        isPlaying = true;
    } else if (!isRecording && isPlaying) {
        button.setTexture(Textures::getTexture(MIC_BUTTON_RED));
        liveRecording.playRecordedSound();
        isPlaying = false;
    }
}
