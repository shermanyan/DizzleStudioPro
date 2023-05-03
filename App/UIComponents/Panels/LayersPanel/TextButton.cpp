//
// Created by Sherman Yan on 5/2/23.
//

#include "TextButton.h"
#include "Fonts.h"
#include "Position.h"
#include "MouseEvents.h"

TextButton::TextButton() {
    setSize(128,40);
    background.setRadius(10);
    background.setFillColor({121,121,121});
    text.setFillColor({185,185,185});
    text.setFont(Fonts::getFont(FontsEnum::NUNITO_BOLD));
    text.setString("Default");
}

void TextButton::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    states.transform *= getTransform();
    target.draw(background,states);
    target.draw(text,states);

}
void TextButton::setText(const std::string& string) {
    text.setString(string);
}

void TextButton::setSize(float x, float y) {
    background.setSize(x, y);
    text.setCharacterSize(background.getSize().y * .6);
    Position::centerText(text,background);
}

void TextButton::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    if(MouseEvents::isHover(getTransform().transformRect(background.getGlobalBounds()),window)) {
        background.setFillColor({100, 100, 100});
    }
    else
        background.setFillColor({121,121,121});
}

void TextButton::update(const sf::RenderWindow &window) {

}

sf::FloatRect TextButton::getGlobalBounds() const {
    return getTransform().transformRect(background.getGlobalBounds());
}

sf::FloatRect TextButton::getLocalBounds() const {
    return background.getLocalBounds();
}
