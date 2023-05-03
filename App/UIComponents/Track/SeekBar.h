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
    int duration = 0;
    float velocity = 0;
    float length = 0;
    Clock clock;

    void updateVelocity();

public:

    SeekBar();

    void setSize(const sf::Vector2f& size);
    void setFillColor(const sf::Color& color);

    void play();
    void pause();
    void restart();

    void setDuration(int duration);
    int getDuration() const;

    void setLength(float length);

    sf::Time getElapsedTime();

    void setRadius(float radius);

    void forward(float amt);
    void rewind(float amt);

    sf::FloatRect getGlobalBounds() const override;
    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;
    void update(const sf::RenderWindow &window) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


    void stop();
};


#endif //DIZZLESTUDIOPRO_SEEKBAR_H
