//
// Created by Brandon Hargitay on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_AUDIOVISUALIZER_H
#define DIZZLESTUDIOPRO_AUDIOVISUALIZER_H
#include <SFML/Audio.hpp>
#include "AppComponent.h"

class AudioVisualizer : public AppComponent , public sf::SoundRecorder {
public:
    AudioVisualizer(unsigned int width, unsigned int height);

    bool startRecording();
    void stopRecording();
//    void setPosition(sf::Vector2f pos);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    virtual bool onProcessSamples(const sf::Int16* samples, std::size_t sampleCount) override;
    std::vector<sf::RectangleShape> visualizerBars;
    unsigned int width;
    unsigned int height;
    const unsigned int numBars = 80;
    std::vector<sf::Int16> sampleBuffer;


    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    sf::FloatRect getGlobalBounds() const override;

    void reposition();

private:




};


#endif //DIZZLESTUDIOPRO_AUDIOVISUALIZER_H
