//
// Created by Sherman Yan on 3/20/23.
//

#include "TextBox.h"

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    target.draw(box);
    target.draw(text);

    if (c.checkStates(ACTIVE) && checkStates(SELECTED))
        target.draw(c);

}

TextBox::TextBox() {
    setupTextBox();
}

TextBox::TextBox(const std::string &label):TextBox() {
    this->label.setString(label);
}

TextBox::TextBox(const sf::Vector2f &boxSize):TextBox() {
    box.setSize(boxSize);
}

void TextBox::setupTextBox() {
    setBoxSize({600, 80});
    setFont(Fonts::getFont(OPEN_SANS));
    setOutlineThickness(5);
    setFillColor(sf::Color::Transparent);
    setOutlineColor(sf::Color::White);

    setState(SELECTED,false);
}
void TextBox::setFont(sf::Font &font) {
    text.setFont(font);
    c.setFont(font);
}

void TextBox::setOutlineThickness(float size) {
    box.setOutlineThickness(size);
}

void TextBox::setBoxSize(const sf::Vector2f &size) {
    box.setSize(size);
    text.setCharacterSize(size.y*.77);
    c.setCharacterSize(text.getCharacterSize());
}

void TextBox::setFillColor(const sf::Color &color) {
    box.setFillColor(color);
}

void TextBox::setCharacterFillColor(const sf::Color& color) {
    text.setFillColor(color);
    c.setFillColor(color);
}

void TextBox::setOutlineColor(const sf::Color &color) {
    box.setOutlineColor(color);
}

void TextBox::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

    if(checkStates(SELECTED)) {
        text.eventHandler(window, event);
    }

    if (MouseEvents::isClick(box,window)) {
        setState(SELECTED, true);
    }
    else if(MouseEvents::isClick(window)) {
        setState(SELECTED, false);
    }

}

void TextBox::update(const sf::RenderWindow &window) {
    if (checkStates(SELECTED)){
        text.updatePosition();
        updateTextBox();

        sf::FloatRect tPos = text.getGlobalBounds();
        c.setPosition(tPos.left + tPos.width, c.getPosition().y);
        c.update();
    }

}

void TextBox::updateTextBox() {

    int buffer = 30;
    if (text.getGlobalBounds().width + buffer> box.getSize().x) {
        hiddenLetters.emplace(*text.front());
        text.pop_front();

    } else if (!hiddenLetters.empty() && text.getGlobalBounds().width +
                                         text.back()->getLetterSpacing() +
                                         hiddenLetters.top().getGlobalBounds().width +
                                         hiddenLetters.top().getLetterSpacing() +buffer < box.getSize().x ){

        text.push_front(hiddenLetters.top());
        hiddenLetters.pop();
    }
}

Typing* TextBox::getText(){
    return &text;
}

sf::FloatRect TextBox::getGlobalBounds() const {
    return box.getGlobalBounds();
}
sf::FloatRect TextBox::getLocalBounds() const {
    return box.getLocalBounds();
}

void TextBox::setPosition(const sf::Vector2f &pos) {
    Transformable::setPosition(pos);
    box.setPosition(pos);
    text.setPosition(pos.x + 10, pos.y);
    c.setPosition(pos);
}

void TextBox::setPosition(float x, float y) {
    setPosition({x, y});
}



