//
// Created by Sherman Yan on 5/1/23.
//

#ifndef DIZZLESTUDIOPRO_DIZZLESTUDIOAPPMAIN_H
#define DIZZLESTUDIOPRO_DIZZLESTUDIOAPPMAIN_H
#include "Application.h"
#include "StudioMain.h"
#include "SplashScreen.h"

class DizzleStudioAppMain: public Application{
private:
    StudioMain studioMain;
    SplashScreen splashScreen;
public:
    DizzleStudioAppMain();

    void eventHandler(RenderWindow &window, const sf::Event &event) override;

    void updater(RenderWindow &window) override;
};


#endif //DIZZLESTUDIOPRO_DIZZLESTUDIOAPPMAIN_H
