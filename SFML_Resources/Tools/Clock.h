//
// Created by Sherman Yan on 4/21/23.
//

#ifndef DIZZLESTUDIOPRO_CLOCK_H
#define DIZZLESTUDIOPRO_CLOCK_H
#include "SFML/Graphics.hpp"

class Clock{
private:
    sf::Clock clock;
    sf::Time time;

    bool on = false;

    float offset = 0;

    sf::Time getElapsedTime();

public:
    Clock();

    void start();
    void stop();
    void toggle();
    void restart();

    void forward(float seconds);
    void rewind(float seconds);

    float getElapsedTimeAsSeconds();


};


#endif //DIZZLESTUDIOPRO_CLOCK_H
