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
    ScrollableContainer<OctaveKeys> keyboard;

public:
    Keyboard();

    void setPosition(const sf::Vector2f & pos);
    void setPosition(float x, float y);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    sf::FloatRect getGlobalBounds() const override;

    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

};


#endif //DIZZLESTUDIOPRO_KEYBOARD_H