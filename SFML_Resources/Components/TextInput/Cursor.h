//
// Created by Sherman Yan on 3/20/23.
//

#ifndef TEXTINPUT_CURSOR_H
#define TEXTINPUT_CURSOR_H

#include "States.h"
#include <SFML/Graphics.hpp>
class Cursor: public sf::Text, public States{
private:
    sf::Clock clock;
    double interval;
    using sf::Text::setString;
public:
    Cursor();
    Cursor(double interval);

    void setCursorCharacter(char cursor);
    void update();

};


#endif //TEXTINPUT_CURSOR_H
