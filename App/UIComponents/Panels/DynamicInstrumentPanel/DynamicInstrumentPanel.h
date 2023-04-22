//
// Created by Sherman Yan on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_DYNAMICINSTRUMENTPANEL_H
#define DIZZLESTUDIOPRO_DYNAMICINSTRUMENTPANEL_H
#include <map>
#include "AppComponent.h"
#include "PanelTypeEnum.h"
#include "BasePanel.h"

#include "KeyboardPanel.h"
#include "EmptyPanel.h"

#include "StaticVisualizerPanel.h"

class DynamicInstrumentPanel: public AppComponent {

private:
    std::map<PanelTypeEnum,BasePanel*> panels;

    BasePanel* currentPanel;

    PanelTypeEnum currentPanelEnum;

    void loadPanel(PanelTypeEnum panel);

    void setChildrenTransform(const sf::Transform &transform) override;

public:
    DynamicInstrumentPanel();
    ~DynamicInstrumentPanel() override;

    void setActivePanel(PanelTypeEnum panel);
    PanelTypeEnum getActivePanel() const;

    BasePanel* getPanel() const;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;
    void update(const sf::RenderWindow &window) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};


#endif //DIZZLESTUDIOPRO_DYNAMICINSTRUMENTPANEL_H
