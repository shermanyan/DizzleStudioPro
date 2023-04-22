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
    float width = ((size.x - (keyboard.front().getKeySpacing() * (keyboard.size() - 1)))/keyboard.size()) ;
    for (auto &o : keyboard)
        o.setSize({width, size.y});

    reposition();

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
}

void Keyboard::update(const sf::RenderWindow &window) {
    for (auto&o :keyboard) {
        o.update(window);
    }
}

void Keyboard::setChildrenTransform(const sf::Transform &transform) {
    for(auto &o : keyboard)
        o.setParentTransform(transform);
}

void Keyboard::reposition() {
    for (int i = 1; i < keyboard.size(); ++i) {
        Position::right(keyboard[i],keyboard[i-1],spacing);
    }
    setChildrenTransform(getTransform());

}

std::pair<int, SoundKeys> Keyboard::getKeyPressed(const sf::RenderWindow &window) const {

    std::pair<int, SoundKeys> keyPressed = {1, NULL_KEY};
    SoundKeys key;

    for (int i = 0; i< keyboard.size(); i++) {
        key = keyboard[i].getKeyPress(window);
        if (key != NULL_KEY) {
            keyPressed.second = keyboard[i].getKeyPress(window);
            keyPressed.first = i + 1;
            break;
        }
    }
    return keyPressed;
}







