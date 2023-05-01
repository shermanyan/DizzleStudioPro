//
// Created by Sherman Yan on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_STUDIOMAIN_H
#define DIZZLESTUDIOPRO_STUDIOMAIN_H
#include "Application.h"
#include "TextInput.h"
#include "DynamicInstrumentPanel.h"
#include "LayersPanel.h"
#include "TrackControls.h"

class StudioMain : public Application{

private:
    DynamicInstrumentPanel dynamicInstrumentPanel;

    LayersPanel trackPanel;
    TextInput projectTitle;

public:

    StudioMain();

    void eventHandler(RenderWindow &window, const sf::Event &event) override;

    void updater(RenderWindow &window) override;

};


#endif //DIZZLESTUDIOPRO_STUDIOMAIN_H
