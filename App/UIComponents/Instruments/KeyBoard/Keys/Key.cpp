//
// Created by Sherman Yan on 4/14/23.
//

#include "Key.h"

//Default Constructor
//Size: 0,0
//Color: white
Key::Key(): Key({0,0}, sf::Color::White) {}

Key::Key(const sf::Vector2f &size, const sf::Color &color) {
    //set key size
    setSize(size);
    //set default clickable range (full key size)
    setClickableRange({0, 0, size.x, size.y});
    //set key background color
    setFillColor(color);
}


void Key::setSize(const sf::Vector2f &size) {
    key.setSize(size);
    setClickableRange({0, 0, size.x, size.y});
}

sf::Vector2f Key::getSize() const {
    return key.getSize();
}

void Key::setFillColor(const sf::Color &color) {
    this->color = color;
    key.setFillColor(color);
}

void Key::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

    if(//event.type == sf::Event::MouseButtonPressed &&
            MouseEvents::isClick(getCombinedTransform().transformRect(clickableRange),window))

    key.setFillColor(color * sf::Color{150,150,150});

    else
        setFillColor(color);
}

void Key::update(const sf::RenderWindow &window) {
}

sf::FloatRect Key::getGlobalBounds() const {
    return getTransform().transformRect(key.getGlobalBounds());
}

sf::FloatRect Key::getLocalBounds() const {
    return key.getLocalBounds();
}

void Key::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(key,states);
}

sf::Color Key::getFillColor() {
    return key.getFillColor();
}

void Key::setClickableRange(const sf::FloatRect &clickableRange) {
    this->clickableRange = clickableRange;
}

void Key::setRadius(float radius) {
    key.setRadius(radius);
}

void Key::setRadius(const float (&radii)[4]) {
    key.setRadius(radii);
}



