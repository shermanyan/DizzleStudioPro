//
// Created by Sherman Yan on 5/3/23.
//

#include "AudioPlayer.h"

void AudioPlayer::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    visualizer.eventHandler(window,event);
}

void AudioPlayer::update(const sf::RenderWindow &window) {
    visualizer.update(window);
}

void AudioPlayer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(visualizer);
}

AudioPlayer::AudioPlayer() {
    visualizer.setPosition(20,100);

}
