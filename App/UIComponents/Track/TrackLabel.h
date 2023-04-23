//
// Created by Sherman Yan on 4/14/23.
//

#ifndef DIZZLESTUDIOPRO_TRACKLABEL_H
#define DIZZLESTUDIOPRO_TRACKLABEL_H

#include "AppComponent.h"
#include "Squircle.h"
#include "Textures.h"
#include "SpriteImage.h"
#include "PanelTypeEnum.h"
#include "Position.h"
#include "MouseEvents.h"
#include "LayerDropDownMenu.h"

class TrackLabel: public AppComponent{

private:
    Squircle label;
    SpriteImage labelImg;

    sf::Color trackColor;

    PanelTypeEnum trackType = EMPTY_PANEL;
public:
    TrackLabel();
    TrackLabel(const sf::Color& labelColor, PanelTypeEnum type = EMPTY_PANEL);
    TrackLabel(const sf::Vector2f& size, const sf::Color& labelColor , PanelTypeEnum type = EMPTY_PANEL);

    sf::Color getTrackColor() const;
    void setTrackColor(const sf::Color &trackColor);

    void setTrack(PanelTypeEnum type);

    PanelTypeEnum getTrackType() const;

    void setSize(const sf::Vector2f& size);


    sf::FloatRect getGlobalBounds() const override;

    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //DIZZLESTUDIOPRO_TRACKLABEL_H
