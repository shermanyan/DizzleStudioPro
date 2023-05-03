//
// Created by Sherman Yan on 5/1/23.
//

#include "DizzleStudioAppMain.h"

DizzleStudioAppMain::DizzleStudioAppMain()
:Application({2000,1125},"Dizzle Studio Pro", {21,21,21})
{
    addComponent(studioMain);
    addComponent(splashScreen);

    studioMain.setState(ACTIVE, false);
    splashScreen.setState(ACTIVE, true);

}

void DizzleStudioAppMain::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    Application::eventHandler(window, event);

    if (splashScreen.checkStates(ACTIVE)) {
        if (event.type == sf::Event::MouseButtonPressed) {
            switch (splashScreen.getAppSwitchStatus()) {
                case STUDIO:
                    splashScreen.setState(ACTIVE, false);
                    studioMain.setState(ACTIVE, true);
                    break;
                case PLAYER:
                    break;
                case NULL_APP:
                    break;
            }
        }
    }
    else if (studioMain.checkStates(ACTIVE)) {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (studioMain.getExitStatus()) {
                splashScreen.setState(ACTIVE, true);
                studioMain.setState(ACTIVE, false);
            }
        }
    }


}

void DizzleStudioAppMain::updater(sf::RenderWindow &window) {
    Application::updater(window);
}
