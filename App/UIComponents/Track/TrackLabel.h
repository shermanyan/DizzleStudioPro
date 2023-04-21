//
// Created by Sherman Yan on 4/14/23.
//

#ifndef DIZZLESTUDIOPRO_TRACKLABEL_H
#define DIZZLESTUDIOPRO_TRACKLABEL_H

#include "AppComponent.h"
#include "Squircle.h"
#include "Textures.h"
#include "SpriteImage.h"
#include "PanelEnum.h"
#include "Position.h"
#include "MouseEvents.h"

class TrackLabel: public AppComponent{

private:
    Squircle label;
    SpriteImage labelImg;

    sf::Color trackColor;

    PanelEnum panelType;

public:
    TrackLabel();
    TrackLabel(const sf::Color& labelColor, PanelEnum type = EMPTY_PANEL);
    TrackLabel(const sf::Vector2f& size, const sf::Color& labelColor , PanelEnum type = EMPTY_PANEL);

    sf::Color getTrackColor() const;
    void setTrackColor(const sf::Color &trackColor);

    void setTrack(PanelEnum type );

    void setSize(const sf::Vector2f& size);

    PanelEnum getTrackType();

    sf::FloatRect getGlobalBounds() const override;

    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //DIZZLESTUDIOPRO_TRACKLABEL_H
