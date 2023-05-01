//
// Created by Sherman Yan on 4/19/23.
//

#include "StudioMain.h"

void StudioMain::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

}

void StudioMain::updater(sf::RenderWindow &window) {

}

StudioMain::StudioMain()
:Application({2000,1125},"Dizzle Studio Pro", {30,30,30}),
dynamicInstrumentPanel({}), trackPanel({})
{
    StudioStatics::panel = &dynamicInstrumentPanel;

    dynamicInstrumentPanel.setPosition(20,700);
    trackPanel.setPosition(20,80);

    projectTitle.setPosition(10,10);
    projectTitle.setTextBoxFont(Fonts::getFont(NUNITO_BOLD));
    projectTitle.setLabelFont(Fonts::getFont(NUNITO_BOLD));
    projectTitle.setLabelString("Untitled");
    projectTitle.setLabelCharacterSize(45);
    projectTitle.setLabelPosition(TextInput::INSIDE);
    projectTitle.setTextBoxSize({600,60});
    projectTitle.setCharacterFillColor({185, 185, 185});
    projectTitle.setLabelFillColor({185, 185, 185});
    projectTitle.toggleBox();

    addComponent(dynamicInstrumentPanel);
    addComponent(trackPanel);
    addComponent(projectTitle);
}

