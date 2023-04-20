//
// Created by Brandon Hargitay on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_STATICAUDIOVISUALIZER_H
#define DIZZLESTUDIOPRO_STATICAUDIOVISUALIZER_H


#include "AppComponent.h"
#include <SFML/Audio.hpp>
#include "Sounds.h"
class StaticAudioVisualizer : public AppComponent {
public:
    StaticAudioVisualizer(const std::string& filePath, const sf::Vector2u& size);
    void setPosition(float posX, float posY);
    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;
    void update(const sf::RenderWindow &window) override;
    sf::SoundBuffer buffer;
    sf::Sound sound;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    std::vector<sf::RectangleShape> visualizerBars;
    unsigned int width;
    unsigned int height;
    sf::Transform transform;

    void updateColors();
    bool isPlaying = false;

};


#endif //DIZZLESTUDIOPRO_STATICAUDIOVISUALIZER_H
