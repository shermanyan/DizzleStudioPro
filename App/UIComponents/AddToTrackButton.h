//
// Created by Brandon Hargitay on 4/30/23.
//

#ifndef DIZZLESTUDIOPRO_ADDTOTRACKBUTTON_H
#define DIZZLESTUDIOPRO_ADDTOTRACKBUTTON_H

#include "AppComponent.h"
#include <SFML/Audio.hpp>
#include "Sounds.h"
#include "Squircle.h"
#include "Position.h"
#include "MouseEvents.h"
#include "Fonts.h"

class AddToTrackButton : public AppComponent {
private:

    Squircle button;
    sf::Text text;

    void init();


public:
    AddToTrackButton();

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    void setParentTransform(const sf::Transform &transform) override;

    AudioNode getAudioNode(const sf::RenderWindow &windo);

    bool isClick(const sf::RenderWindow& window) const;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //DIZZLESTUDIOPRO_ADDTOTRACKBUTTON_H
