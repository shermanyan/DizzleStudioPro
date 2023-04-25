//
// Created by Sherman Yan on 4/14/23.
//

#include "BasePanel.h"

BasePanel::BasePanel(): BasePanel({1960, 407}) {
}

BasePanel::BasePanel(const sf::Vector2f &size) {

    setSize(size);
    setFillColor({51,51,51});
    setBorderColor({121,121,121});

    setBorderWidth(20);
    setRadius(20);

    Position::center(inside,outside);


}

void BasePanel::setFillColor(const sf::Color &color) {
    inside.setFillColor(color);
}

void BasePanel::setBorderColor(const sf::Color &color) {
    outside.setFillColor(color);

}

void BasePanel::setBorderWidth(float width) {
    this->borderWidth = width;
}


void BasePanel::setSize(const sf::Vector2f &size) {
    outside.setSize(size);
    inside.setSize(size - sf::Vector2f{borderWidth * 2,borderWidth * 2});
}

void BasePanel::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

}

void BasePanel::update(const sf::RenderWindow &window) {

}

void BasePanel::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    states.transform *= getTransform();

    target.draw(outside, states);
    target.draw(inside, states);

}

void BasePanel::setRadius(float radius) {
    outside.setRadius(radius);
    inside.setRadius(radius/2);
}

void BasePanel::setRadius(const float (&radii)[4]) {
    outside.setRadius(radii);
    inside.setRadius({radii[0]/2,radii[1]/2,radii[2]/2,radii[3]/2});

}

sf::FloatRect BasePanel::getGlobalBounds() const {
    return getTransform().transformRect(outside.getGlobalBounds());
}

sf::FloatRect BasePanel::getLocalBounds() const {
    return outside.getLocalBounds();
}

sf::Vector2f BasePanel::getSize() {
    return outside.getSize();
}

AudioNode BasePanel::getKeyPressed(const sf::RenderWindow &window) const {
    return {};
}

AudioNode BasePanel::getKeyRelease(const sf::RenderWindow &window, const sf::Event& event) const {
    return {};
}






