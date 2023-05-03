//
// Created by Sherman Yan on 5/1/23.
//

#include "DizzleStudioAppMain.h"

DizzleStudioAppMain::DizzleStudioAppMain()
:Application({2000,1125},"Dizzle Studio Pro", {30,30,30})
{
    addComponent(studioMain);
    addComponent(splashScreen);
}

//added#########################

void DizzleStudioAppMain::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    Application::eventHandler(window, event);


}

void DizzleStudioAppMain::updater(sf::RenderWindow &window) {
    Application::updater(window);
}
//added#########################
