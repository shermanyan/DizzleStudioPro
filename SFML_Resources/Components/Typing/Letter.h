//
// Created by Sherman Yan on 3/5/23.
//

#ifndef LETTERS_H
#define LETTERS_H
#include <SFML/Graphics.hpp>

class Letter: public sf::Text {
public:
    Letter();
    Letter(char c);
    Letter(const Letter& letter);

};


#endif //LETTERS_H
