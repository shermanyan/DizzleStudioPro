//
// Created by Sherman Yan on 4/16/23.
//

#ifndef DIZZLESTUDIOPRO_KEYBOARD_H
#define DIZZLESTUDIOPRO_KEYBOARD_H

#include "AppComponent.h"
#include "OctaveKeys.h"
#include "ScrollableContainer.h"

class Keyboard: public AppComponent{
private:
    std::vector<OctaveKeys> keyboard;

    void setChildrenTransform(const sf::Transform& transform) override;
public:
    Keyboard();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    sf::FloatRect getGlobalBounds() const override;

    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

};


#endif //DIZZLESTUDIOPRO_KEYBOARD_H
