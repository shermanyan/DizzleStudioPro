//
// Created by Sherman Yan on 4/22/23.
//

#ifndef DIZZLESTUDIOPRO_TIMEBAR_H
#define DIZZLESTUDIOPRO_TIMEBAR_H

#include "AppComponent.h"
#include "Squircle.h"
#include "Position.h"

class TimeBar: public AppComponent {
private:
    Squircle background;
    std::vector<Squircle> intervalBars;

    int duration = 0;

    void position();
    void resize();
public:
    TimeBar();

    void setSize(const sf::Vector2f& size);
    void setDuration(int seconds);
    int getDuration()const ;

    sf::FloatRect getGlobalBounds() const override;

    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;
    void update(const sf::RenderWindow &window) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};


#endif //DIZZLESTUDIOPRO_TIMEBAR_H
