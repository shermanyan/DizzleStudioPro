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
#include "LayerDropDownMenu.h"

class Layer: public AppComponent {
private:

    std::unique_ptr<Track> track;

    LayerDropDownMenu dropDownMenu;
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

    std::map<float, std::vector<AudioNode>> getAudioTrack();


};



#endif //DIZZLESTUDIOPRO_LAYER_H
