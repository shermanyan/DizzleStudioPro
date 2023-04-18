#include <SFML/Graphics.hpp>
#include "Position.h"
#include "Squircle.h"
#include "Fonts.h"
#include "MouseEvents.h"
#include <iostream>
int main()
{

    srand(time(0));

    sf::Vector2u windowSize({2000,1125});
    sf::RenderWindow window({windowSize.x,windowSize.y}, "SFML Tutorial");
    window.setFramerateLimit(60);
    sf::Clock clock;
    sf::Text timer;

    timer.setFont(Fonts::getFont(OPEN_SANS));
    timer.setPosition(20,20);
    timer.setCharacterSize(50);
    clock.restart();

    Squircle seek({10, 100},5);
    Squircle track({1000,120},10);
    Squircle button({100,100}, 20);

    std::vector<Squircle> nodes;

    button.setPosition(500,500);
    track.setFillColor({36,41,46});
    track.setPosition(100,100);
    Position::center(seek,track);
    Position::alignLeft(seek,track);

    float seconds = 20;
    float velocity = track.getSize().x/(seconds * 1000000);

    bool draw = false;

    while(window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::MouseButtonPressed && MouseEvents::isClick(button.getGlobalBounds(), window)) {
                button.setFillColor(sf::Color::Red);
                nodes.emplace_back();
                nodes.back().setSize(10, 100);
                nodes.back().setRadius(1);
                nodes.back().setFillColor(sf::Color((int)(rand() % 255 + 1) ,(int)(rand() % 255 + 1),(int)(rand() % 255 + 1)));
                Position::center(nodes.back(), seek);
                draw = true;
            } else if (event.type == sf::Event::MouseButtonReleased){
                draw = false;
                button.setFillColor(sf::Color::White);
            }

        }
        if (draw && !nodes.empty()){
            nodes.back().setSize(sf::Vector2f((float) seek.getPosition().x - nodes.back().getPosition().x,
                                          nodes.back().getSize().y));
        }

        timer.setString(std::to_string(clock.getElapsedTime().asMilliseconds() * 0.001));
        seek.setPosition(track.getPosition().x + (velocity * clock.getElapsedTime().asMicroseconds()), seek.getPosition().y);

        if (seek.getPosition().x >= track.getPosition().x + track.getSize().x)
            clock.restart();

        window.clear();
        window.draw(button);
        window.draw(timer);
        window.draw(track);
        for (auto &b : nodes) {
            window.draw(b);
        }
        window.draw(seek);

        window.display();
    }
    return 0;
}
