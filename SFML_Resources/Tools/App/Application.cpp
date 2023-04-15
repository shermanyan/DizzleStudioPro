//
// Created by Dave R. Smith on 2/14/23.
//

#include "Application.h"

Application::Application(): Application("Default Application",sf::Color::Black){
}

Application::Application(const std::string &windowName): Application(windowName,sf::Color::Black){
}

Application::Application(const std::string &windowName, const sf::Color &bgColor){
    this->windowName = windowName;
    this->bgColor = bgColor;
    this->windowSize = {1920, 1080};
    create({windowSize.x, windowSize.y,32}, windowName);
    setFramerateLimit(60);

//    r.setSize({100, 100});
}

void Application::addComponent(AppComponent &component) {
    components.push_back(&component);

}

void Application::run(){

    setTitle(windowName);
    setSize(windowSize);
    setView(sf::View({0, 0,(float)windowSize.x, (float)windowSize.y}));

    while (isOpen()) {
        sf::Event event;

        windowEventListener(event);

        windowUpdater();

        clear(bgColor);

        for (sf::Drawable *c: components) {
            draw(*c);
        }
//        draw(r);

        display();
    }
}

void Application::windowUpdater() {
    for (Updatable *u: components)
        u->update(*this);

    updater(*this);
}

void Application::windowEventListener(sf::Event &event) {
    while (pollEvent(event)) {
        if (sf::Event::Closed == event.type)
            close();
        else if (sf::Event::Resized == event.type) {
            if(resizable) {
                setView(sf::View({0, 0, (float)event.size.width, (float)event.size.height}));
                setSize({event.size.width, event.size.height});
            } else {
                setSize(windowSize);
                setView(sf::View({0, 0, (float) windowSize.x, (float) windowSize.y}));
            }
        }
        for (EventHandleable *c: components)
            c->eventHandler(*this, event);

        eventHandler(*this, event);
    }
}

void Application::setWindowSize(const sf::Vector2u &windowSize) {
    this->windowSize = windowSize;
}

void Application::disableResize() {
    resizable = false;
}

void Application::updater(sf::RenderWindow &window) {

}

void Application::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

}


