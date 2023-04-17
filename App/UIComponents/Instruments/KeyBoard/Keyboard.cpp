//
// Created by Sherman Yan on 4/16/23.
//

#include "Keyboard.h"

Keyboard::Keyboard() {

    for(int i = 0; i<3; i++){
        keyboard.emplace_back();
    }

    for (int i = 1; i < keyboard.size(); ++i) {
        Position::right(keyboard[i], keyboard[i-1],10);
    }

}

void Keyboard::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (auto&o :keyboard) {
        target.draw(o,states);
    }
}

sf::FloatRect Keyboard::getGlobalBounds() const {
//    return getTransform().transformRect(getPosition().x, getPosition().y , keyboard.size() * keyboard.front().getGlobalBounds().width, );
}

sf::FloatRect Keyboard::getLocalBounds() const {
//    return keyboard.getLocalBounds();
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


}

void Keyboard::setChildrenTransform(const sf::Transform &transform) {
    for(auto &o : keyboard)
        o.setParentTransform(transform);
}



