//
// Created by Sherman Yan on 3/20/23.
//

#include "TextInput.h"
#include <iostream>

TextInput::TextInput(){
}

TextInput::TextInput(const std::string &label):TextInput() {
    setState(HIDDEN,false);

    setLabelString(label);

}

void TextInput::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

    textBox.eventHandler(window,event);

    if(event.TextEntered) {
        MultiText *text = textBox.getText();

        std::string s = text->getString();

        if (isdigit(s[s.length() - 1])) {
            text->setFillColor(sf::Color::Red, s.length() - 1);
        } else if (isOperator(s[s.length() - 1])) {
            text->setFillColor(sf::Color::Green, s.length() - 1);
        }

        colorWord(text,"int",sf::Color::Blue);
        colorWord(text,"double",sf::Color::Blue);
        colorWord(text,"float",sf::Color::Blue);
    }
}

void TextInput::colorWord(MultiText *&text, const std::string& target, const sf::Color& color) {
    std::string str = text->getString();
    unsigned long t = target.length() , s = str.length();
    if (s >= t && str.substr(s - t).find(target) != std::string::npos)
        text->setFillColor(color, s - t, t);

}

void TextInput::update(const sf::RenderWindow &window) {
    textBox.update(window);

    if (!getString().empty())
        empty = false;
    else
        empty = true;

}

bool TextInput::isOperator(char c) {
    char  ops[7] = {'+','-','*','/','%','=','^'};
    for (auto o: ops) {
        if (c == o)
            return true;
    }
    return false;
}

void TextInput::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(!checkStates(HIDDEN)) {
        states.transform *= getTransform();
        target.draw(textBox, states);
        if(position == INSIDE && empty && !textBox.checkStates(SELECTED))
            target.draw(label, states);
    }
}

sf::FloatRect TextInput::getGlobalBounds() const {
    sf::FloatRect bounds , tBound = textBox.getGlobalBounds(),lBound = label.getGlobalBounds();
    sf::Vector2f lPos = label.getPosition(), tPos = textBox.getPosition();
    bounds.left = label.getPosition().x;
    bounds.top =  tPos.y > lPos.y? tPos.y: lPos.y;
    if(position == INSIDE)
        bounds.width = tBound.width;
    else
        bounds.width = lBound.width + tBound.width;
    bounds.height = lBound.height > tBound.height? lBound.height: tBound.height;

    return getTransform().transformRect(bounds);
}

sf::FloatRect TextInput::getLocalBounds() const {
    sf::FloatRect bounds , tBound = textBox.getLocalBounds(),lBound = label.getLocalBounds();
    bounds.width = lBound.width + tBound.width;
    bounds.height = lBound.height > tBound.height? lBound.height: tBound.height;

    return bounds;
}


void TextInput::setLabelString(const std::string &label) {
    this->label.setString(label);
}

void TextInput::setLabelCharacterSize(unsigned int size) {
    this->label.setCharacterSize(size);
}

void TextInput::setLabelFont(sf::Font &font) {
    this->label.setFont(font);
}

void TextInput::setTextBoxFont(sf::Font &font) {
    textBox.setFont(font);
}

void TextInput::setCharacterFillColor(const sf::Color &color) {
    textBox.setCharacterFillColor(color);
}

void TextInput::setOutlineThickness(float size) {
    textBox.setOutlineThickness(size);
}

void TextInput::setTextBoxSize(const sf::Vector2f &size) {
    textBox.setBoxSize(size);
}

void TextInput::setTextBoxFillColor(const sf::Color &color) {
    textBox.setFillColor(color);
}

void TextInput::setTextBoxOutlineColor(const sf::Color &color) {
    textBox.setOutlineColor(color);
}

void TextInput::setLabelFillColor(const sf::Color &color) {
    label.setFillColor(color);
}

void TextInput::toggleBox() {
    textBox.toggleBoxState();
}

void TextInput::setString(const std::string &string) {
    textBox.setString(string);
}

void TextInput::setChildrenTransform(const sf::Transform &transform) {
    textBox.setParentTransform(transform);
}

std::string TextInput::getString(){
    MultiText *text = textBox.getText();

    std::string s = text->getString();
    return s;
}

void TextInput::setLabelPosition(TextInput::LabelPosition position) {
    this->position = position;
    Position::alignLeft(label,textBox);

    label.setPosition(label.getPosition() + sf::Vector2f{10,0});
}

bool TextInput::isEmpty() {
    return textBox.isEmpty();
}

