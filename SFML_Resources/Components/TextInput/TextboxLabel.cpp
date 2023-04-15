//
// Created by Sherman Yan on 3/20/23.
//

#include "TextboxLabel.h"
#include "Fonts.h"

TextboxLabel::TextboxLabel():TextboxLabel("") {
}

TextboxLabel::TextboxLabel(const std::string &text) {
    setupLabel();
    setLabelString(text);
}

void TextboxLabel::setupLabel() {
    setLabelFont(Fonts::getFont(OPEN_SANS));
    setLabelCharacterSize(60);
    setLabelFillColor(sf::Color::White);
}

void TextboxLabel::setLabelString(const std::string &label) {
    setString(label);
}

void TextboxLabel::setLabelCharacterSize(unsigned int size) {
    setCharacterSize(size);
}

void TextboxLabel::setLabelFont(sf::Font &font) {
    setFont(font);
}
void TextboxLabel::setLabelFillColor(const sf::Color &color) {
    setFillColor(color);
}


