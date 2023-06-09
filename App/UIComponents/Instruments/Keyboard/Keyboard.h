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

    float spacing = 10;
    unsigned int numOctaves = 1;


    void setChildrenTransform(const sf::Transform& transform) override;

    void setupKeyboard();

    void reposition();


public:
    static const unsigned int STARTING_OCTAVE ;   //change this value to what octave you want to start at

    Keyboard();
    Keyboard(unsigned int numOctaves);
    Keyboard(unsigned int numOctaves, const sf::Vector2f& size);

    void setSize(const sf::Vector2f& size);

    sf::Vector2f getSize()const;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    sf::FloatRect getGlobalBounds() const override;
    sf::FloatRect getLocalBounds() const override;

//    std::vector<Key*> getKeys();

//    AudioNode getKeyRelease(const sf::RenderWindow &window, const sf::Event& event) const;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    float getSpacing() const;

    void setSpacing(float spacing);

    unsigned int getNumOctaves() const;


    std::vector<Key *> getKeys();
};


#endif //DIZZLESTUDIOPRO_KEYBOARD_H
