//
// Created by Brandon Hargitay on 4/28/23.
//

#ifndef DIZZLESTUDIOPRO_DRUMPADPANEL_H
#define DIZZLESTUDIOPRO_DRUMPADPANEL_H

#include "DrumPad.h"
#include "BasePanel.h"

class DrumPadPanel : public BasePanel {
public:
    DrumPad drumPad;
    DrumPadPanel();

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void setChildrenTransform(const sf::Transform &transform) override;

private:

};


#endif //DIZZLESTUDIOPRO_DRUMPADPANEL_H
