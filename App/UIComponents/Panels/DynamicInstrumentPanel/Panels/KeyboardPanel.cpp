//
// Created by Sherman Yan on 4/19/23.
//

#include "KeyboardPanel.h"

unsigned int KeyboardPanel::octaveCount = 2;

KeyboardPanel::KeyboardPanel(): BasePanel{} {

    keyboard = {octaveCount, BasePanel::getSize() - sf::Vector2f {60, 60}};
    Position::center(keyboard,*this);
}

void KeyboardPanel::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    BasePanel::eventHandler(window, event);
    keyboard.eventHandler(window,event);
}

void KeyboardPanel::update(const sf::RenderWindow &window) {
    BasePanel::update(window);
    keyboard.update(window);
}

void KeyboardPanel::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    BasePanel::draw(target, states);
    states.transform *= getTransform();
    target.draw(keyboard,states);
}

void KeyboardPanel::setChildrenTransform(const sf::Transform &transform) {
    keyboard.setParentTransform(transform);
}

std::vector<Key *> KeyboardPanel::getKeys(const sf::RenderWindow &window) {
    return keyboard.getKeys(window);
}

//std::vector<Key*> KeyboardPanel::getKeys() {
//    return keyboard.getKeys();
//}



//AudioNode KeyboardPanel::getKeyPressed(const sf::RenderWindow &window) const {
//    return keyboard.getKeyPressed(window);
//}
//
//AudioNode KeyboardPanel::getKeyRelease(const sf::RenderWindow &window, const sf::Event& event) const {
//    return keyboard.getKeyRelease(window, event);
//}

//void KeyboardPanel::setPosition(const sf::Vector2f &pos) {
//    BasePanel::setPosition(pos);
//}
//
//void KeyboardPanel::setPosition(float x, float y) {
//    setPosition({x, y});
//}
//
