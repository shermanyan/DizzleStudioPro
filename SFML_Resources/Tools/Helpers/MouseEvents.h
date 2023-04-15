//
// Created by Sherman Yan on 02/16/23.
//

#ifndef MOUSEEVENTS_H
#define MOUSEEVENTS_H

#include <SFML/Graphics.hpp>

class MouseEvents {
public:
    template<class T>
    static bool isHover(const T& Obj , const sf::RenderWindow& window);

    template<class T>
    static bool isClick(const T& Obj , const sf::RenderWindow& window);

    static bool isClick(const sf::RenderWindow& window);


};
template<class T>
bool MouseEvents::isHover(const T &Obj, const sf::RenderWindow &window) {
    sf::Vector2f mPos = (sf::Vector2f)sf::Mouse::getPosition(window);
    return Obj.getGlobalBounds().contains(mPos);
}

template<class T>
bool MouseEvents::isClick(const T &Obj, const sf::RenderWindow &window) {
    return isHover(Obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) ;
}

#endif //MOUSEEVENTS_H
