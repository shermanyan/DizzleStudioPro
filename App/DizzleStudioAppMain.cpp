//
// Created by Sherman Yan on 5/1/23.
//

#include "DizzleStudioAppMain.h"

DizzleStudioAppMain::DizzleStudioAppMain()
:Application({2000,1125},"Dizzle Studio Pro", {21,21,21})
{
    addComponent(studioMain);
    addComponent(splashScreen);
    addComponent(audioPlayer);

    studioMain.setState(ACTIVE, false);
    splashScreen.setState(ACTIVE, true);
    audioPlayer.setState(ACTIVE, false);
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
                    splashScreen.setState(ACTIVE, false);
                    audioPlayer.setState(ACTIVE, true);
                    setWindowSize({2000,500});
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
    }else if (audioPlayer.checkStates(ACTIVE)) {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (audioPlayer.getExitStatus()) {
                splashScreen.setState(ACTIVE, true);
                audioPlayer.setState(ACTIVE, false);
                setWindowSize({2000,1125});
            }
        }
    }


}

void DizzleStudioAppMain::updater(sf::RenderWindow &window) {
    Application::updater(window);
}
