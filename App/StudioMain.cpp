//
// Created by Sherman Yan on 4/19/23.
//

#include "StudioMain.h"

void StudioMain::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

}

void StudioMain::updater(sf::RenderWindow &window) {

}

StudioMain::StudioMain() : Application({2000,1125},"Dizzle Studio Pro", {30,30,30}) {


    projectTitle.setPosition(10,10);
    projectTitle.setTextBoxFont(Fonts::getFont(NUNITO_BOLD));
    projectTitle.setTextBoxSize({600,60});
    projectTitle.setCharacterFillColor({185, 185, 185});
    projectTitle.toggleBox();
    projectTitle.setString("Untitled");


    dynamicInstrumentPanel.setPosition(20,700);

    trackPanel.setPosition(20,80);
    trackPanel.setInstrumentPanel(&dynamicInstrumentPanel);

    addComponent(dynamicInstrumentPanel);
    addComponent(trackPanel);
    addComponent(projectTitle);
}

