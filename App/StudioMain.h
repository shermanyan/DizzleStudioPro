//
// Created by Sherman Yan on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_STUDIOMAIN_H
#define DIZZLESTUDIOPRO_STUDIOMAIN_H
#include "AppComponent.h"
#include "TextInput.h"
#include "DynamicInstrumentPanel.h"
#include "LayersPanel.h"
#include "TrackControls.h"

class StudioMain: public AppComponent{

private:
    DynamicInstrumentPanel dynamicInstrumentPanel;

    LayersPanel layersPanel;
    TextInput projectTitle;

    TextButton xport,xit;

public:

    StudioMain();

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;
    void update(const sf::RenderWindow &window) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    bool getExitStatus();
};


#endif //DIZZLESTUDIOPRO_STUDIOMAIN_H
