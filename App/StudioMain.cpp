//
// Created by Sherman Yan on 4/19/23.
//

#include "StudioMain.h"

void StudioMain::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    dynamicInstrumentPanel.eventHandler(window,event);
    layersPanel.eventHandler(window,event);
    projectTitle.eventHandler(window,event);

    xport.eventHandler(window,event);
    xit.eventHandler(window,event);

    if (sf::Event::MouseButtonPressed == event.type) {
        if (MouseEvents::isHover(xport.getGlobalBounds(), window)) {
            printf("Export Clicked ");
            std::string name = projectTitle.getString();
            if (name.empty())
                name = "Untitled";
            layersPanel.exportTrack(name + ".wav");
        } else if (MouseEvents::isHover(xit.getGlobalBounds(), window)) {
            xit.toggleState(SELECTED);
            printf("Exit Clicked ");
        }
    }
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

    xport.setText("Export");
    xport.setSize(128,40);
    xit.setText("Exit");
    xit.setSize(83,40);

    Position::alignRight(xit,layersPanel);
    Position::top(xit,layersPanel,10);
    Position::center(xport,xit);
    Position::left(xport,xit,30);


}

void StudioMain::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    target.draw(dynamicInstrumentPanel);
    target.draw(layersPanel);
    target.draw(projectTitle);

    target.draw(xport);
    target.draw(xit);


}

bool StudioMain::getExitStatus() {

    if (xit.checkStates(SELECTED)) {
        xit.setState(SELECTED, false);
        return true;
    }
    return false;
}

