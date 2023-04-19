//
// Created by Sherman Yan on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_KEYBOARDPANEL_H
#define DIZZLESTUDIOPRO_KEYBOARDPANEL_H

#include "DynamicInstrumentPanel.h"
#include "Keyboard.h"

class KeyboardPanel: public DynamicInstrumentPanel{
private:
    Keyboard keyboard;
public:
    KeyboardPanel();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    void setPosition(const sf::Vector2f & pos);
    void setPosition(float x, float y);

private:
    void setChildrenTransform(const sf::Transform &transform) override;


};


#endif //DIZZLESTUDIOPRO_KEYBOARDPANEL_H
