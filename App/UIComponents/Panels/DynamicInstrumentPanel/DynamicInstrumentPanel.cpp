//
// Created by Sherman Yan on 4/19/23.
//

#include "DynamicInstrumentPanel.h"
#include <iostream>

DynamicInstrumentPanel::DynamicInstrumentPanel() {

    setActivePanel(EMPTY);
}


void DynamicInstrumentPanel::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

    currentPanel->eventHandler(window,event);
}

void DynamicInstrumentPanel::update(const sf::RenderWindow &window) {

    currentPanel->update(window);
}

void DynamicInstrumentPanel::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    states.transform *= getTransform();
    target.draw(*currentPanel,states);
}

void DynamicInstrumentPanel::setActivePanel(InstrumentsEnum panel) {
    if (panels.count(panel) == 0) {
        loadPanel(panel);
        setChildrenTransform(getTransform());
    }
    currentPanelEnum = panel;
    currentPanel = panels.at(panel).get();
}


void DynamicInstrumentPanel::loadPanel(InstrumentsEnum panel) {

    switch (panel) {

        case KEYBOARD: {
            panels[KEYBOARD] = std::make_unique<KeyboardPanel>();
            break;
        }
        case DRUMPAD:{
            panels[DRUMPAD] = std::make_unique<DrumPadPanel>();
            break;
        }
        case AUDIO: {
            panels[AUDIO] = std::make_unique<StaticVisualizerPanel>();
            break;
        }
        case VOCAL: {
            panels[VOCAL] = std::make_unique<AudioRecordingPanel>();
            break;
        }
        case EMPTY: {
            panels[EMPTY] = std::make_unique<EmptyPanel>();
            break;
        }
        default:
            throw;
    }

}

void DynamicInstrumentPanel::setChildrenTransform(const sf::Transform &transform) {
    for(auto& p :panels)
        p.second->setParentTransform(transform);
}

InstrumentsEnum DynamicInstrumentPanel::getActivePanel() const {
    return currentPanelEnum;
}

BasePanel* DynamicInstrumentPanel::getPanel() const {
    return currentPanel;
}
