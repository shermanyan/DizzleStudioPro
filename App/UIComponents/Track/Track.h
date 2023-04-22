//
// Created by Sherman Yan on 4/14/23.
//

#ifndef DIZZLESTUDIOPRO_TRACK_H
#define DIZZLESTUDIOPRO_TRACK_H

#include "AppComponent.h"
#include "Squircle.h"

class Track: public AppComponent{
private:
    Squircle background;

public:
    Track();

    sf::FloatRect getGlobalBounds() const override;
    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;
    void update(const sf::RenderWindow &window) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};


#endif //DIZZLESTUDIOPRO_TRACK_H
