//
// Created by Sherman Yan on 4/14/23.
//

#include "SeekBar.h"
SeekBar::SeekBar() {

}

void SeekBar::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::P)
            clock.toggle();
        else if (event.key.code == sf::Keyboard::Right)
            clock.forward(1);
        else if (event.key.code == sf::Keyboard::Left)
            clock.rewind(1);
    }
}

void SeekBar::update(const sf::RenderWindow &window) {

    bar.setPosition((velocity * clock.getElapsedTimeAsSeconds()), bar.getPosition().y);

    if (bar.getPosition().x >= length)
        clock.stop();

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

void SeekBar::setDuration(float duration) {
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

    clock.start();
}

void SeekBar::pause() {
    clock.stop();
}

void SeekBar::toggleLoop() {
    loop = !loop;
}

float SeekBar::getElapsedTime() {
    return clock.getElapsedTimeAsSeconds();
}

void SeekBar::updateVelocity() {
    velocity = length/duration;
}

void SeekBar::setRadius(float radius) {
    bar.setRadius(radius);
}


