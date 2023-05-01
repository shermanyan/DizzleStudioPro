//
// Created by Sherman Yan on 4/21/23.
//

#include "Clock.h"

Clock::Clock() {

}

void Clock::start() {
    on = true;
    clock.restart();
}

void Clock::stop() {
    time = getElapsedTime();
    on = false;
}

sf::Time Clock::getElapsedTime() {
    if (on)
        return clock.getElapsedTime() + time;
    else
        return time;
}

void Clock::toggle() {
    if (on)
        stop();
    else
        start();

}

void Clock::restart() {
    time = sf::Time::Zero;
    offset = 0;
    clock.restart();
    on = true;
}

void Clock::forward(float seconds) {
    offset += seconds ;

}

void Clock::rewind(float seconds) {
    offset -= seconds;
}

float Clock::getElapsedTimeAsSeconds() {
    return getElapsedTime().asSeconds() + offset;
}

