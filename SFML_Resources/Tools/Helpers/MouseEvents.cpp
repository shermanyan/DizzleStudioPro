//
// Created by Sherman Yan on 02/16/23.
//
#include "MouseEvents.h"


bool MouseEvents::isClick(const sf::RenderWindow &window) {
    sf::FloatRect w = {0,0,(float)window.getSize().x, (float)window.getSize().y};
    sf::Vector2f mPos = (sf::Vector2f)sf::Mouse::getPosition(window);
    return w.contains(mPos) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}


bool MouseEvents::isHover(const sf::FloatRect& bounds, const sf::RenderWindow &window) {
    sf::Vector2f mPos = (sf::Vector2f)sf::Mouse::getPosition(window);
    return bounds.contains(mPos);
}

bool MouseEvents::isClick(const sf::FloatRect& bounds, const sf::RenderWindow &window) {
    return isHover(bounds, window) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}



