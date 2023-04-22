//
// Created by Sherman Yan on 4/22/23.
//

#include "TimeBar.h"

TimeBar::TimeBar() {
    background.setFillColor({51,51,51});
    background.setRadius(10);

    setSize({1530,40});
    setDuration(10);
}

void TimeBar::setSize(const sf::Vector2f &size) {
    background.setSize(size);

    resize();
}

void TimeBar::setDuration(int seconds) {
    if (seconds > 0) {
        this->duration = seconds * 2;

        while (intervalBars.size() < duration ) {
            intervalBars.emplace_back(sf::Vector2f{}, 2.5, sf::Color{94, 94, 94});
        }
        while (intervalBars.size() > duration  && !intervalBars.empty())
            intervalBars.pop_back();

        resize();
        position();
    }
}

int TimeBar::getDuration() const {
    return duration/2;
}


void TimeBar::resize() {
    if (!intervalBars.empty())
        for (int i = 0; i< intervalBars.size(); i++) {
            intervalBars[i].setOrigin(intervalBars[i].getSize().x/2,0);
            intervalBars[i].setSize(5, background.getSize().y * (i%2 == 0 ? .5: .7));
        }
}



void TimeBar::position() {

    float spacing = ((background.getSize().x ) -20) / (duration -1);

    if (!intervalBars.empty())
        for (int i = 0; i < intervalBars.size(); i++) {
            intervalBars[i].setPosition((i*spacing) + 10,0);
            Position::alignBottom(intervalBars[i],background);
        }

}


void TimeBar::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    if(event.KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket)) {
        printf("A");
        setDuration((duration / 2) + 1);
    }
    else if (event.KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket)) {
        setDuration((duration / 2) - 1);
        printf("S");
    }

}

void TimeBar::update(const sf::RenderWindow &window) {

}

void TimeBar::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();

    target.draw(background,states);
    for (auto &i: intervalBars) {
        target.draw(i,states);
    }
}

sf::FloatRect TimeBar::getGlobalBounds() const {
    return getTransform().transformRect(background.getGlobalBounds());
}

sf::FloatRect TimeBar::getLocalBounds() const {
    return background.getLocalBounds();
}

