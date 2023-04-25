//
// Created by Sherman Yan on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_KEYBOARDPANEL_H
#define DIZZLESTUDIOPRO_KEYBOARDPANEL_H

#include "BasePanel.h"
#include "Keyboard.h"

class KeyboardPanel: public BasePanel{
private:
    Keyboard keyboard;

protected:
    void setChildrenTransform(const sf::Transform &transform) override;

public:
    KeyboardPanel();

    AudioNode getKeyPressed(const sf::RenderWindow& window) const override;

    AudioNode getKeyRelease(const sf::RenderWindow &window, const sf::Event& event) const override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

//    void setPosition(const sf::Vector2f & pos) override;
//    void setPosition(float x, float y) override;

};


#endif //DIZZLESTUDIOPRO_KEYBOARDPANEL_H
