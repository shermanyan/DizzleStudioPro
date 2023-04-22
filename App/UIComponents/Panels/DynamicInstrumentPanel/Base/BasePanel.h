//
// Created by Sherman Yan on 4/14/23.
//

#ifndef DIZZLESTUDIOPRO_BASEPANEL_H
#define DIZZLESTUDIOPRO_BASEPANEL_H

#include "AppComponent.h"
#include "Squircle.h"
#include "Position.h"
#include "PanelTypeEnum.h"

class BasePanel: public AppComponent {

private:
    Squircle inside, outside;
    float borderWidth = 20;

public:
    BasePanel();
    BasePanel(const sf::Vector2f& size);

    void setSize(const sf::Vector2f& size);
    sf::Vector2f getSize();

    void setRadius(float radius);
    void setRadius(const float (&radii)[4]);

    void setFillColor(const sf::Color& color);
    void setBorderColor(const sf::Color& color);
    void setBorderWidth(float width);

    sf::FloatRect getGlobalBounds() const override;

    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};


#endif //DIZZLESTUDIOPRO_BASEPANEL_H
