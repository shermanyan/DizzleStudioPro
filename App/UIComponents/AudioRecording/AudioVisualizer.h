//
// Created by Brandon Hargitay on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_AUDIOVISUALIZER_H
#define DIZZLESTUDIOPRO_AUDIOVISUALIZER_H
#include <SFML/Audio.hpp>
#include "AppComponent.h"
#include "Squircle.h"
class AudioVisualizer : public AppComponent , public sf::SoundRecorder {
public:

    std::vector<sf::Int16> sampleBuffer;
    unsigned int width;
    unsigned int height;
    const unsigned int numBars = 53;

    AudioVisualizer(unsigned int width, unsigned int height);
    std::vector<Squircle> visualizerBars;

    bool startRecording();
    void stopRecording();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


    void saveRecordedSoundToFile(const std::string& filename);

    void playRecordedSound();

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    sf::FloatRect getGlobalBounds() const override;


private:

    sf::SoundBuffer recordedSoundBuffer;
    sf::Sound recordedSound;

    virtual bool onProcessSamples(const sf::Int16* samples, std::size_t sampleCount) override;

    void reposition();

    void resetVisualizerBars();

};


#endif //DIZZLESTUDIOPRO_AUDIOVISUALIZER_H
