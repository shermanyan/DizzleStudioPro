//
// Created by Sherman Yan on 3/19/23.
//

#include "KeyboardShortcuts.h"

bool KeyboardShortcuts::isUndo() {
    return ((sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) || sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) &&sf::Keyboard::isKeyPressed(sf::Keyboard::Z));
}
