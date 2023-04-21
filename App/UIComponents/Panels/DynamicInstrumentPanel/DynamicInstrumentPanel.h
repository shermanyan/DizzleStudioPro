//
// Created by Sherman Yan on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_DYNAMICINSTRUMENTPANEL_H
#define DIZZLESTUDIOPRO_DYNAMICINSTRUMENTPANEL_H
#include <map>
#include "AppComponent.h"
#include "PanelEnum.h"
#include "BasePanel.h"

#include "KeyboardPanel.h"
#include "EmptyPanel.h"

#include "StaticVisualizerPanel.h"

class DynamicInstrumentPanel: public AppComponent {

private:
    std::map<PanelEnum,BasePanel*> panels;

    BasePanel* currentPanel;

    PanelEnum currentPanelEnum;

    void loadPanel(PanelEnum panel);

    void setChildrenTransform(const sf::Transform &transform) override;

public:
    DynamicInstrumentPanel();
    ~DynamicInstrumentPanel() override;

    void setActivePanel(PanelEnum panel);
    PanelEnum getActivePanel() const;

    BasePanel* getPanel() const;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;
    void update(const sf::RenderWindow &window) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};


#endif //DIZZLESTUDIOPRO_DYNAMICINSTRUMENTPANEL_H
