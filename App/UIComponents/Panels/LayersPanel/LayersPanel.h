//
// Created by Sherman Yan on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_LAYERSPANEL_H
#define DIZZLESTUDIOPRO_LAYERSPANEL_H

#include "AppComponent.h"
#include "Squircle.h"
#include "TrackLabel.h"
#include "DynamicInstrumentPanel.h"

class LayersPanel: public AppComponent {
private:

    DynamicInstrumentPanel* instrumentPanel = nullptr;

    PanelEnum panelType;

    Squircle background;
    std::vector<TrackLabel> labels;
    std::vector<sf::Color> trackColors = {{167,42,54},{14,122,40},{41,107,170},{175,143,54}};


protected:
    void setChildrenTransform(const sf::Transform &transform) override;

public:
    LayersPanel();

    void setInstrumentPanel(DynamicInstrumentPanel *instrumentPanel);

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //DIZZLESTUDIOPRO_LAYERSPANEL_H
