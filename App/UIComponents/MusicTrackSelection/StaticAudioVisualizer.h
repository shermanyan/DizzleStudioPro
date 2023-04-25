//
// Created by Brandon Hargitay on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_STATICAUDIOVISUALIZER_H
#define DIZZLESTUDIOPRO_STATICAUDIOVISUALIZER_H


#include "AppComponent.h"
#include <SFML/Audio.hpp>
#include "Sounds.h"
#include "Squircle.h"
#include "Position.h"

class StaticAudioVisualizer : public AppComponent {
public:
    StaticAudioVisualizer(const std::string& filePath, const sf::Vector2u& size);

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;
    void update(const sf::RenderWindow &window) override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void loadVisualizer(const std::string& filePath);

    sf::FloatRect getGlobalBounds() const override;

    sf::SoundBuffer buffer;

    sf::Sound sound;

    bool isPlaying = false;

private:

    std::vector<Squircle> visualizerBars;
    unsigned int width;
    unsigned int height;

    float spacing = 15;

    void updateColors();

    void reposition();



};


#endif //DIZZLESTUDIOPRO_STATICAUDIOVISUALIZER_H
