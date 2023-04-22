//
// Created by Sherman Yan on 4/19/23.
//

#include "StudioMain.h"

void StudioMain::eventHandler(sf::RenderWindow &window, const sf::Event &event) {


//    if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::K) {
//        dynamicInstrumentPanel.setActivePanel(KEYBOARD);
//
//    } else if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::V) {
//        dynamicInstrumentPanel.setActivePanel(VOCAL);
//    } else if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::E)
//        dynamicInstrumentPanel.setActivePanel(EMPTY_PANEL);

}

void StudioMain::updater(sf::RenderWindow &window) {

}

StudioMain::StudioMain() : Application({2000,1125},"Dizzle Studio Pro", {30,30,30}) {


    projectTitle.setPosition(10,10);
    projectTitle.setTextBoxFont(Fonts::getFont(NUNITO_BOLD));
    projectTitle.toggleBox();
    projectTitle.setString("Untitled");


    dynamicInstrumentPanel.setPosition(20,700);

    trackPanel.setPosition(20,80);
    trackPanel.setInstrumentPanel(&dynamicInstrumentPanel);

    addComponent(dynamicInstrumentPanel);
    addComponent(trackPanel);
    addComponent(projectTitle);
}

