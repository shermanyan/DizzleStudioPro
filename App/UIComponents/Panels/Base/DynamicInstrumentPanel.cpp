//
// Created by Sherman Yan on 4/14/23.
//

#include "DynamicInstrumentPanel.h"

DynamicInstrumentPanel::DynamicInstrumentPanel(): DynamicInstrumentPanel({1960,407}) {
}

DynamicInstrumentPanel::DynamicInstrumentPanel(const sf::Vector2f &size) {
    setSize(size);
    setFillColor({51,51,51});
    setBorderColor({121,121,121});

    setBorderWidth(20);
    setRadius(20);

    Position::center(inside,outside);

}

void DynamicInstrumentPanel::setFillColor(const sf::Color &color) {
    inside.setFillColor(color);
}

void DynamicInstrumentPanel::setBorderColor(const sf::Color &color) {
    outside.setFillColor(color);

}

void DynamicInstrumentPanel::setBorderWidth(float width) {
    this->borderWidth = width;
}


void DynamicInstrumentPanel::setSize(const sf::Vector2f &size) {
    outside.setSize(size);
    inside.setSize(size - sf::Vector2f{borderWidth * 2,borderWidth * 2});
}

void DynamicInstrumentPanel::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

}

void DynamicInstrumentPanel::update(const sf::RenderWindow &window) {

}

void DynamicInstrumentPanel::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    states.transform *= getTransform();

    target.draw(outside,states);
    target.draw(inside,states);

}

void DynamicInstrumentPanel::setRadius(float radius) {
    outside.setRadius(radius);
    inside.setRadius(radius/2);
}

void DynamicInstrumentPanel::setRadius(const float (&radii)[4]) {
    outside.setRadius(radii);
    inside.setRadius({radii[0]/2,radii[1]/2,radii[2]/2,radii[3]/2});

}

sf::FloatRect DynamicInstrumentPanel::getGlobalBounds() const {
    return getTransform().transformRect(outside.getGlobalBounds());
}

sf::FloatRect DynamicInstrumentPanel::getLocalBounds() const {
    return outside.getLocalBounds();
}

sf::Vector2f DynamicInstrumentPanel::getSize() {
    return outside.getSize();
}





