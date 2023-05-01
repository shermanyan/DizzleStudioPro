//
// Created by Sherman Yan on 4/30/23.
//

#ifndef DIZZLESTUDIOPRO_TRACKCONTROLS_H
#define DIZZLESTUDIOPRO_TRACKCONTROLS_H

#include "AppComponent.h"
#include "Squircle.h"
#include "SpriteImage.h"
#include "Textures.h"
#include "Position.h"
#include "MouseEvents.h"
#include "StudioStatics.h"

class TrackControls: public AppComponent {
private:
    sf::Clock clock;

    Squircle background;
    sf::CircleShape record;
    SpriteImage play, pause, forward, rewind, loop;


public:
    TrackControls();

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;
    void update(const sf::RenderWindow &window) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};


#endif //DIZZLESTUDIOPRO_TRACKCONTROLS_H
