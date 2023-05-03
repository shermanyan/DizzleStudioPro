//
// Created by Sherman Yan on 4/14/23.
//

#include "SeekBar.h"
SeekBar::SeekBar() {

}

void SeekBar::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

}

void SeekBar::update(const sf::RenderWindow &window) {
    bar.setPosition((velocity * clock.getElapsedTimeAsSeconds()), bar.getPosition().y);

        if (bar.getPosition().x >= length) {
            stop();
            if (checkStates(LOOP)) {
                restart();
            }
        } else if(checkStates(STOP))
            toggleState(STOP);


}

void SeekBar::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();

    target.draw(bar,states);
}

sf::FloatRect SeekBar::getGlobalBounds() const {
    return getTransform().transformRect(bar.getGlobalBounds());
}

sf::FloatRect SeekBar::getLocalBounds() const {
    return bar.getLocalBounds();
}

void SeekBar::setDuration(int duration) {
    SeekBar::duration = duration;
    updateVelocity();
}

void SeekBar::setLength(float length) {
    SeekBar::length = length;
    updateVelocity();
}

void SeekBar::setSize(const sf::Vector2f &size) {
    bar.setSize(size);
    setOrigin(bar.getSize().x/2 , 0);
}

void SeekBar::setFillColor(const sf::Color &color) {
    bar.setFillColor(color);
}

void SeekBar::play() {
    setState(PLAY,true);
    setState(STOP,false);
    clock.start();
}

void SeekBar::restart() {
    setState(PLAY,true);
    setState(STOP,false);
    clock.restart();
}


void SeekBar::pause() {
    setState(PLAY,false);
    clock.stop();
}

sf::Time SeekBar::getElapsedTime() {
    return clock.getElapsedTime();
}

void SeekBar::updateVelocity() {
    velocity = length/duration;
}

void SeekBar::setRadius(float radius) {
    bar.setRadius(radius);
}

int SeekBar::getDuration() const {
    return duration;
}

void SeekBar::stop() {
    pause();
    setState(STOP,true);
}

void SeekBar::forward(float amt) {
    float n = clock.getElapsedTimeAsSeconds() + amt ;
    clock.forward(n < duration? amt : duration - clock.getElapsedTimeAsSeconds());
}

void SeekBar::rewind(float amt) {
    float n = clock.getElapsedTimeAsSeconds() - amt;

    clock.rewind(n > 0? amt: clock.getElapsedTimeAsSeconds());
}


