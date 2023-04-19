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
    StaticAudioVisualizer(const std::string& filePath, unsigned int width, unsigned int height);

    void setScale(float scaleX, float scaleY);
    void setPosition(float posX, float posY);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    std::vector<sf::RectangleShape> visualizerBars;
    unsigned int width;
    unsigned int height;
    const unsigned int numBars = 50;
    sf::Transform transform;
public:
    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;
    // Add this line

};


#endif //DIZZLESTUDIOPRO_STATICAUDIOVISUALIZER_H
