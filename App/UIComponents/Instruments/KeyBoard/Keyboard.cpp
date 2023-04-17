//
// Created by Sherman Yan on 4/16/23.
//

#include "Keyboard.h"

Keyboard::Keyboard() {

    for(int i = 0; i<2; i++){
        keyboard.push_back({});
    }

    keyboard.setBound({0, 0, 1920,367});

}

void Keyboard::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(keyboard,states);
}

sf::FloatRect Keyboard::getGlobalBounds() const {
    return getTransform().transformRect(keyboard.getGlobalBounds());
}

sf::FloatRect Keyboard::getLocalBounds() const {
    return keyboard.getLocalBounds();
}

void Keyboard::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    keyboard.eventHandler(window,event);
}

void Keyboard::update(const sf::RenderWindow &window) {
    keyboard.update(window);
}

void Keyboard::setPosition(const sf::Vector2f &pos) {
    Transformable::setPosition(pos);
    keyboard.setParentTransform(getTransform());
}

void Keyboard::setPosition(float x, float y) {
    setPosition({x,y});
}

