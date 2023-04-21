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

void DynamicInstrumentPanel::setActivePanel(PanelEnum panel) {
    if (panels.count(panel) == 0) {
        loadPanel(panel);
        setChildrenTransform(getTransform());
    }

    currentPanel = panels.at(panel);

}

DynamicInstrumentPanel::~DynamicInstrumentPanel() {

    for(auto &p: panels)
        delete p.second;
}


void DynamicInstrumentPanel::loadPanel(PanelEnum panel) {
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
            panels[AUDIO]= new StaticVisualizerPanel;
            break;
        }
        case VOCAL: {
            throw;
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

//void DynamicInstrumentPanel::setPosition(const sf::Vector2f &pos) {
//    Transformable::setPosition(pos);
//    setChildrenTransform(getTransform());
//}
//
//void DynamicInstrumentPanel::setPosition(float x, float y) {
//    setPosition({x,y});
//}
//
