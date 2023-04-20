//
// Created by Sherman Yan on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_LAYERSPANEL_H
#define DIZZLESTUDIOPRO_LAYERSPANEL_H

#include "AppComponent.h"
#include "Squircle.h"

class LayersPanel: public AppComponent {
private:
    Squircle background;

public:
    LayersPanel();

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //DIZZLESTUDIOPRO_LAYERSPANEL_H
