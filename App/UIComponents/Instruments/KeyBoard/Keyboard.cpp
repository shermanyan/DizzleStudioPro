//
// Created by Sherman Yan on 4/16/23.
//

#include "Keyboard.h"

Keyboard::Keyboard() : Keyboard(1) {
}

Keyboard::Keyboard(unsigned int numOctaves){
    this->numOctaves = numOctaves;
    setupKeyboard();
}

Keyboard::Keyboard(unsigned int numOctaves, const sf::Vector2f &size) {
    this->numOctaves = numOctaves;
    setupKeyboard();
    setSize(size);
}




void Keyboard::setupKeyboard() {
    for(int i = 0; i < numOctaves; i++)
        keyboard.emplace_back();

}

void Keyboard::setSize(const sf::Vector2f &size) {
    float width = (size.x/keyboard.size()) - (keyboard.front().getKeySpacing() * (keyboard.size() - 1));

    for (auto &o : keyboard)
        o.setSize({width, size.y});

}

sf::Vector2f Keyboard::getSize() const {
    sf::FloatRect bounds = getLocalBounds();
    return {bounds.width,bounds.height};
}

float Keyboard::getSpacing() const {
    return spacing;
}

void Keyboard::setSpacing(float spacing) {
    Keyboard::spacing = spacing;
    setSize(getSize());
}

unsigned int Keyboard::getNumOctaves() const {
    return numOctaves;
}



void Keyboard::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (auto&o :keyboard) {
        target.draw(o,states);
    }
}

sf::FloatRect Keyboard::getGlobalBounds() const {
    sf::FloatRect bounds = keyboard.front().getGlobalBounds();
    bounds.width = (bounds.width * keyboard.size()) + (spacing*(keyboard.size()-1));

    return getTransform().transformRect(bounds);
}
sf::FloatRect Keyboard::getLocalBounds() const {
    sf::FloatRect bounds = getGlobalBounds();
    bounds.left = 0;
    bounds.top = 0;
    return bounds;
}

void Keyboard::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    for (auto&o :keyboard) {
        o.eventHandler(window,event);
    }
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        setPosition((sf::Vector2f )sf::Mouse::getPosition(window));

}

void Keyboard::update(const sf::RenderWindow &window) {
    for (auto&o :keyboard) {
        o.update(window);
    }

    for (int i = 1; i < keyboard.size(); ++i) {
        sf::FloatRect s = (keyboard[i].getGlobalBounds());
        sf::FloatRect r = (keyboard[i-1].getGlobalBounds());
        keyboard[i].setPosition({r.left + r.width + 10, s.top});
    }
    setChildrenTransform(getTransform());
}

void Keyboard::setChildrenTransform(const sf::Transform &transform) {
    for(auto &o : keyboard)
        o.setParentTransform(transform);
}







