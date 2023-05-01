//
// Created by Sherman Yan on 4/19/23.
//

#include "StudioMain.h"

void StudioMain::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    dynamicInstrumentPanel.eventHandler(window,event);
    layersPanel.eventHandler(window,event);
    projectTitle.eventHandler(window,event);

}

void StudioMain::update(const sf::RenderWindow &window) {
    dynamicInstrumentPanel.update(window);
    layersPanel.update(window);
    projectTitle.update(window);

}

StudioMain::StudioMain()
:dynamicInstrumentPanel({}), layersPanel({})
{
    StudioStatics::panel = &dynamicInstrumentPanel;

    dynamicInstrumentPanel.setPosition(20,700);
    layersPanel.setPosition(20,80);

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

}

void StudioMain::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(dynamicInstrumentPanel);
    target.draw(layersPanel);
    target.draw(projectTitle);
}

