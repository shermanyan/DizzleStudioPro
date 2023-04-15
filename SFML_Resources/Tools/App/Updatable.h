//
// Created by Sherman Yan on 11/17/22.
//

#ifndef UPDATABLE_H
#define UPDATABLE_H
#include <SFML/Graphics.hpp>

class Updatable {
public:
    virtual void update(const sf::RenderWindow &window) = 0;
};


#endif //UPDATABLE_H
