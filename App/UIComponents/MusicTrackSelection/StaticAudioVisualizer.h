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
    void setPosition(const sf::Vector2f & pos);
    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;
    void update(const sf::RenderWindow &window) override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    bool isPlaying = false;

private:

    std::vector<sf::RectangleShape> visualizerBars;
    unsigned int width;
    unsigned int height;
    sf::Transform transform;

    void updateColors();

};


#endif //DIZZLESTUDIOPRO_STATICAUDIOVISUALIZER_H
