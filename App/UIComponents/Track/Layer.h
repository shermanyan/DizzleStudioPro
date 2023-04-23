//
// Created by Sherman Yan on 4/14/23.
//

#ifndef DIZZLESTUDIOPRO_LAYER_H
#define DIZZLESTUDIOPRO_LAYER_H


#include "AppComponent.h"
#include "Squircle.h"
#include "TrackLabel.h"
#include "DynamicInstrumentPanel.h"
#include "Track.h"
#include "LayerDropDownMenu.h"
class Layer: public AppComponent {
private:

    DynamicInstrumentPanel* instrumentPanel = nullptr;

    TrackLabel label;

    Track track;

    sf::Color trackColor = {0,0,0};

    LayerDropDownMenu dropDownMenu;

protected:
    void setChildrenTransform(const sf::Transform &transform) override;

public:
    Layer();
    Layer(PanelTypeEnum trackType);

    void setTrackColor(const sf::Color& color);
    void setTrack(PanelTypeEnum type);
    PanelTypeEnum getTrackType() const;

    void setInstrumentPanel(DynamicInstrumentPanel *instrumentPanel);

    sf::FloatRect getGlobalBounds() const override;

    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};



#endif //DIZZLESTUDIOPRO_LAYER_H
