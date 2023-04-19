//
// Created by Sherman Yan on 02/16/23.
//

#ifndef MOUSEEVENTS_H
#define MOUSEEVENTS_H

#include <SFML/Graphics.hpp>

class MouseEvents {
public:
    static bool isHover(const sf::FloatRect& bounds , const sf::RenderWindow& window);


    static bool isClick(const sf::FloatRect& bounds, const sf::RenderWindow& window);

    static bool isClick(const sf::RenderWindow& window);


};


#endif //MOUSEEVENTS_H
