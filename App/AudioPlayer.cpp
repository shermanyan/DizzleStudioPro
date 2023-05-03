//
// Created by Sherman Yan on 5/3/23.
//

#include "AudioPlayer.h"

void AudioPlayer::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    visualizer.eventHandler(window, event);
    if (sf::Event::MouseButtonPressed == event.type) {
        if (MouseEvents::isHover(xit.getGlobalBounds(), window)) {
            xit.toggleState(SELECTED);
            printf("Exit Clicked ");
        }
    }
}

void AudioPlayer::update(const sf::RenderWindow &window) {
    visualizer.update(window);
}

void AudioPlayer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(visualizer);
    target.draw(xit);

}

AudioPlayer::AudioPlayer() {
    visualizer.setPosition(20,70);

    xit.setText("Exit");
    xit.setSize(83,40);

    Position::alignRight(xit,visualizer);
    Position::top(xit,visualizer,10);

}

bool AudioPlayer::getExitStatus() {

    if (xit.checkStates(SELECTED)) {
        xit.setState(SELECTED, false);
        return true;
    }
    return false;
}
