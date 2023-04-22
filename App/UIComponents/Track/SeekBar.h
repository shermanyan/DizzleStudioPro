//
// Created by Sherman Yan on 4/14/23.
//

#ifndef DIZZLESTUDIOPRO_SEEKBAR_H
#define DIZZLESTUDIOPRO_SEEKBAR_H

#include "AppComponent.h"
#include "Squircle.h"
#include "Clock.h"

class SeekBar: public AppComponent{
private:
    Squircle bar;
    float duration = 0;
    float velocity = 0;
    float length = 0;
    Clock clock;

    bool loop = false;

    void updateVelocity();

public:

    SeekBar();

    void setSize(const sf::Vector2f& size);
    void setFillColor(const sf::Color& color);

    void play();
    void pause();
    void toggleLoop();

    void setDuration(float duration);
    void setLength(float length);

    float getElapsedTime();

    void setRadius(float radius);


    sf::FloatRect getGlobalBounds() const override;
    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;
    void update(const sf::RenderWindow &window) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


};


#endif //DIZZLESTUDIOPRO_SEEKBAR_H
