#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
int main()
{
    sf::RenderWindow window({720, 420, 32}, "Sound");
    sf::SoundBufferRecorder recorder;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    sf::RectangleShape rect({10, 10});
    rect.setPosition(100,100);

    sf::Clock clock1;
    bool record = false;

    recorder.stop();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
                window.close();
            else if (event.key.code == sf::Keyboard::R) {
                recorder.start();
                record = true;
                clock1.restart();
            }
            else if (event.key.code == sf::Keyboard::S){
                recorder.stop();
            }

        }
        if (buffer.getSampleCount() > 0) {
            buffer = recorder.getBuffer();
            std::cout << buffer.getSamples()[buffer.getSampleCount()] << " ";
            rect.setSize({10, float(buffer.getSamples()[buffer.getSampleCount()]) * 100});
        }




        window.clear();
        window.draw(rect);
        window.display();
    }
    return 0;
}

