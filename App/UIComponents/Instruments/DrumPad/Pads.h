//
// Created by Sherman Yan on 4/14/23.
//

#ifndef DIZZLESTUDIOPRO_PADS_H
#define DIZZLESTUDIOPRO_PADS_H

#include "AppComponent.h"
#include "Squircle.h"
#include "Position.h"
#include "MouseEvents.h"
#include "SoundKeys.h"
#include "Sounds.h"
#include "AudioNode.h"
#include <SFML/Audio.hpp>
#include "Fonts.h"

class Pads: public AppComponent, public AudioNode {
private:
    Squircle pad;
    sf::Text text;
    SoundKeys keyType = NULL_KEY;
    sf::Sound sound;

public:

    Pads();
    Pads(const sf::Vector2f &size);
    void setPosition(const sf::Vector2f &position);
    bool isClick(const sf::RenderWindow& window) const;

    void setSize(const sf::Vector2f &size);
    void getSize();

    void loadSound();

    AudioNode getKeyType() const;
    void setupText();

    sf::FloatRect getGlobalBounds() const override;
    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;
    void update(const sf::RenderWindow &window) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void setText(const std::string &string);
};


#endif //DIZZLESTUDIOPRO_PADS_H
