#include <SFML/Graphics.hpp>
#include <iostream>
#include "Analyser.h"
int main() {

    sf::RenderWindow window ({1280,800}, "DizzleStudio Pro");
    window.setFramerateLimit(60);

    //Visualizer Constructor
    Analyser visualizer ("Sounds/TestSounds/Naruto.wav", window.getSize());
    visualizer.setPosition(100, 700);

    //plays sound and activates the visualizer
    visualizer.activateVisulizer();

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
                visualizer.sound.play();
                std::cout << "Play";
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::BackSpace)){
                visualizer.sound.pause();
                std::cout << "Pause";
            }
        }

        visualizer.updateVisualizer();
        window.clear();
        window.draw(visualizer);
        window.display();
    }



    return 0;
}
