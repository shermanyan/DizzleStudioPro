//
// Created by Sherman Yan on 4/14/23.
//

#ifndef DIZZLESTUDIOPRO_LAYER_H
#define DIZZLESTUDIOPRO_LAYER_H

#include "StudioStatics.h"

#include "AppComponent.h"
#include "Squircle.h"
#include "TrackLabel.h"
#include "DynamicInstrumentPanel.h"

#include "KeyboardTrack.h"
#include "AudioTrack.h"
#include "VocalTrack.h"
#include "DrumPadTrack.h"

#include <algorithm>
#include <future>

class Layer: public AppComponent {
private:

    std::unique_ptr<Track> track;

    TrackLabel label;
    sf::Sound test;
    sf::SoundBuffer buffer1;

    void setChildrenTransform(const sf::Transform &transform) override;

public:
    Layer();

    void setTrackColor(const sf::Color& color);
    void setTrack(InstrumentsEnum type);
    InstrumentsEnum getTrackType() const;

    sf::FloatRect getGlobalBounds() const override;

    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void playAudioMap(const std::map<float, std::vector<AudioNode>>& audioMap);

    sf::SoundBuffer concatenateSounds(const std::map<float, std::vector<AudioNode>>& audioMap, unsigned int targetSampleRate);
    sf::SoundBuffer convertToMono(const sf::SoundBuffer& buffer);
    sf::SoundBuffer resampleSoundBuffer(const sf::SoundBuffer& buffer, unsigned int targetSampleRate);

    };



#endif //DIZZLESTUDIOPRO_LAYER_H
