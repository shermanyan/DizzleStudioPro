//
// Created by Sherman Yan on 3/20/23.
//

#ifndef TEXTINPUT_TEXTBOXLABEL_H
#define TEXTINPUT_TEXTBOXLABEL_H

#include <SFML/Graphics.hpp>

class TextboxLabel : public sf::Text{
public:
    TextboxLabel();
    TextboxLabel(const std::string& text);

    void setupLabel();

    void setLabelString(const std::string &label);

    void setLabelCharacterSize(unsigned int size);

    void setLabelFont(sf::Font &font);

    void setLabelFillColor(const sf::Color &color);
};


#endif //TEXTINPUT_TEXTBOXLABEL_H
