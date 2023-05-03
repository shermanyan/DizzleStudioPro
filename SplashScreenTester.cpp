//
// Created by Brandon Hargitay on 5/1/23.
//

#include "Application.h"
#include "SplashScreen.h"

int main(){
    Application tester;
    tester.setWindowSize({2000,1125});
    tester.setBgColor({20,20,20});
    SplashScreen splash;

    tester.addComponent(splash);
    tester.run();

    return 0;
};