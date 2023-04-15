//
// Created by Sherman Yan on 3/5/23.
//

#ifndef TYPING_H
#define TYPING_H
#include <SFML/Graphics.hpp>
#include "MultiText.h"
#include "KeyboardShortcuts.h"
class Typing: public MultiText{
public:
    Typing();
    void eventHandler(const sf::Window& window, const sf::Event& event);
};


#endif //TYPING_H
