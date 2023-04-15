#include <iostream>
#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow window ({1280,720, 32}, "test");
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        window.display();
    }



    return 0;
}
