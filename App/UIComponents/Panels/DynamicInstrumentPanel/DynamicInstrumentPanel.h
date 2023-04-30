//
// Created by Sherman Yan on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_DYNAMICINSTRUMENTPANEL_H
#define DIZZLESTUDIOPRO_DYNAMICINSTRUMENTPANEL_H
#include <map>
#include "AppComponent.h"
#include "InstrumentsEnum.h"
#include "BasePanel.h"

#include "KeyboardPanel.h"
#include "EmptyPanel.h"
#include "StaticVisualizerPanel.h"
#include "AudioRecordingPanel.h"

#include "StaticVisualizerPanel.h"
#include "AudioRecordingPanel.h"

class DynamicInstrumentPanel: public AppComponent {

private:
    std::map<InstrumentsEnum,std::unique_ptr<BasePanel>> panels;

    BasePanel* currentPanel = nullptr;

    InstrumentsEnum currentPanelEnum;

    void loadPanel(InstrumentsEnum panel);

    void setChildrenTransform(const sf::Transform &transform) override;

public:
    DynamicInstrumentPanel();

    void setActivePanel(InstrumentsEnum panel);
    InstrumentsEnum getActivePanel() const;

    BasePanel* getPanel();

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;
    void update(const sf::RenderWindow &window) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};


#endif //DIZZLESTUDIOPRO_DYNAMICINSTRUMENTPANEL_H
