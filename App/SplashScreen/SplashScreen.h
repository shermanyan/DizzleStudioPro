//
// Created by Brandon Hargitay on 5/1/23.
//

#ifndef DIZZLESTUDIOPRO_SPLASHSCREEN_H
#define DIZZLESTUDIOPRO_SPLASHSCREEN_H

#include "AppComponent.h"
#include <SFML/Graphics.hpp>
#include "Fonts.h"
#include "Position.h"
#include "Textures.h"
#include "SpriteImage.h"
#include <iostream>
#include "MouseEvents.h"
#include "States.h"

class SplashScreen : public AppComponent{

private:
    SpriteImage sprite;
    SpriteImage musicMixer;
    SpriteImage musicPlayer;

    sf::Text dizzleStudio;
    sf::Text pro;

    sf::Text startButton;

    sf::Text credits;

    sf::Text welcome;
    sf::Text getStarted;

    sf::Vector2f initialDizzleStudioPosition;
    sf::Clock animationClock;
    float duration;

    void fade();
    void fall();
    void transition();

    void moveUp(const sf::Vector2f & offset);

public:
    SplashScreen();

    void setUpText();
    void setUpTextures();

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;
    void update(const sf::RenderWindow &window) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};




#endif //DIZZLESTUDIOPRO_SPLASHSCREEN_H
