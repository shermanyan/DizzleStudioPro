//
// Created by Sherman Yan on 4/16/23.
//

#include "Keyboard.h"

Keyboard::Keyboard() {

    for(int i = 0; i<1; i++){
        keyboard.emplace_back();
    }

}

void Keyboard::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (auto&o :keyboard) {
        target.draw(o,states);
    }
}

sf::FloatRect Keyboard::getGlobalBounds() const {
    sf::FloatRect bounds = keyboard.front().getGlobalBounds();
    bounds.width = (bounds.width * keyboard.size()) + (10*(keyboard.size()-1));

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



