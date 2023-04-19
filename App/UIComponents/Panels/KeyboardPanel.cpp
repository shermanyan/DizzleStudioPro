//
// Created by Sherman Yan on 4/19/23.
//

#include "KeyboardPanel.h"

KeyboardPanel::KeyboardPanel():DynamicInstrumentPanel{} {

    keyboard = {2,DynamicInstrumentPanel::getSize()- sf::Vector2f {60,60}};
    Position::center(keyboard,*this);
}

void KeyboardPanel::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    DynamicInstrumentPanel::eventHandler(window, event);
    keyboard.eventHandler(window,event);
}

void KeyboardPanel::update(const sf::RenderWindow &window) {
    DynamicInstrumentPanel::update(window);
    keyboard.update(window);
}

void KeyboardPanel::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    DynamicInstrumentPanel::draw(target, states);
    target.draw(keyboard,states);
}

void KeyboardPanel::setChildrenTransform(const sf::Transform &transform) {
    keyboard.setParentTransform(getTransform());
}

void KeyboardPanel::setPosition(const sf::Vector2f &pos) {
    DynamicInstrumentPanel::setPosition(pos);
    keyboard.setPosition(pos);
    Position::center(keyboard,*this);
}

void KeyboardPanel::setPosition(float x, float y) {
    setPosition({x, y});
}

