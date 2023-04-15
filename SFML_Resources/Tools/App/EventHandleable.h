//
// Created by Sherman Yan on 11/17/22.
//

#ifndef EVENTHANDLEABLE_H
#define EVENTHANDLEABLE_H
#include <SFML/Graphics.hpp>

class EventHandleable {
public:
    virtual void eventHandler(sf::RenderWindow& window, const sf::Event& event) = 0;
};


#endif //EVENTHANDLEABLE_H
