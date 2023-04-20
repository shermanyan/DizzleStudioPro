//
// Created by Sherman Yan on 2/14/23.
//

#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include "AppComponent.h"

class Application: public sf::RenderWindow{
private:
    std::vector<AppComponent*> components;
    sf::Color bgColor;
    std::string windowName;
    sf::Vector2u windowSize;
    bool resizable = true;

//    sf::RectangleShape r;

    void windowEventListener(sf::Event &event);
    void windowUpdater();

    using sf::Window::setSize;
public:
    Application();
    Application(const std::string& windowName);
    Application(const std::string& windowName, const sf::Color &bgColor);
    Application(const sf::Vector2u& windowSize, const std::string& windowName, const sf::Color &bgColor);

    void setBgColor(const sf::Color &bgColor);

    void setWindowSize(const sf::Vector2u& windowSize);
    void addComponent(AppComponent& component);
    void disableResize();
    void run();

    virtual void eventHandler(sf::RenderWindow& window, const sf::Event& event);
    virtual void updater(sf::RenderWindow& window);
};


#endif //APPLICATION_H
