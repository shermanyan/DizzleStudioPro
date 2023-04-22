//
// Created by Sherman Yan on 4/19/23.
//

#include "DynamicInstrumentPanel.h"
#include <iostream>

DynamicInstrumentPanel::DynamicInstrumentPanel() {

    setActivePanel(EMPTY_PANEL);
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

void DynamicInstrumentPanel::setActivePanel(PanelTypeEnum panel) {
    if (panels.count(panel) == 0) {
        loadPanel(panel);
        setChildrenTransform(getTransform());
    }
    currentPanelEnum = panel;
    currentPanel = panels.at(panel);
}

DynamicInstrumentPanel::~DynamicInstrumentPanel() {

    for(auto &p: panels)
        delete p.second;
}


void DynamicInstrumentPanel::loadPanel(PanelTypeEnum panel) {
    switch (panel) {

        case KEYBOARD: {
            panels[KEYBOARD] = new KeyboardPanel;
            break;
        }
        case DRUMPAD:{
            throw;
            break;
        }
        case AUDIO: {
<<<<<<< HEAD
            panels[AUDIO]= new AudioRecordingPanel;
            break;
        }
        case VOCAL: {
            panels[VOCAL]= new StaticVisualizerPanel;
=======
            panels[AUDIO] = new StaticVisualizerPanel;
            break;
        }
        case VOCAL: {
            panels[VOCAL] = new AudioRecordingPanel;
>>>>>>> Sherman
            break;
        }
        case EMPTY_PANEL: {
            panels[EMPTY_PANEL] = new EmptyPanel;
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

PanelTypeEnum DynamicInstrumentPanel::getActivePanel() const {
    return currentPanelEnum;
}

BasePanel* DynamicInstrumentPanel::getPanel() const {
    return currentPanel;
}

//void DynamicInstrumentPanel::setPosition(const sf::Vector2f &pos) {
//    Transformable::setPosition(pos);
//    setChildrenTransform(getTransform());
//}
//
//void DynamicInstrumentPanel::setPosition(float x, float y) {
//    setPosition({x,y});
//}
//
