//
// Created by Sherman Yan on 4/16/23.
//

#include "Keyboard.h"

Keyboard::Keyboard() {

    for(int i = 0; i<2; i++){
        keyboard.emplace_back();
    }

    Position::right(keyboard.front(), keyboard.back(),10);

}

void Keyboard::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (auto&o :keyboard) {
        target.draw(o,states);

    }
}

sf::FloatRect Keyboard::getGlobalBounds() const {
//    return getTransform().transformRect(keyboard.getGlobalBounds());
}

sf::FloatRect Keyboard::getLocalBounds() const {
//    return keyboard.getLocalBounds();
}

void Keyboard::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    for (auto&o :keyboard) {
        o.eventHandler(window,event);
    }
}

void Keyboard::update(const sf::RenderWindow &window) {
    for (auto&o :keyboard) {
        o.update(window);
    }
}

void Keyboard::setPosition(const sf::Vector2f &pos) {
    Transformable::setPosition(pos);

    for (auto&o :keyboard) {
        o.setParentTransform(getTransform());
    }
}

void Keyboard::setPosition(float x, float y) {
    setPosition({x,y});
}

