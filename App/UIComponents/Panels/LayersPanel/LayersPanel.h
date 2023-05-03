//
// Created by Sherman Yan on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_LAYERSPANEL_H
#define DIZZLESTUDIOPRO_LAYERSPANEL_H

#include "AppComponent.h"
#include "Squircle.h"
#include "Layer.h"
#include "DynamicInstrumentPanel.h"
#include "SeekBar.h"
#include "TimeBar.h"
#include "TrackControls.h"
#include "GetBuffer.h"
#include "TextButton.h"

class LayersPanel: public AppComponent {
private:


    Squircle background;

    std::vector<Layer> layers;

    sf::Color trackColors[4] = {{167,42,54},{14,122,40},{41,107,170},{175,143,54}};

    SeekBar seek;

    TimeBar timeBar;

    TrackControls trackControls;

    sf::SoundBuffer combinedBuffer;
    sf::Sound sound;

    std::vector<sf::SoundBuffer> buffers;
    std::vector<sf::Sound> sounds;

    std::map<float, std::vector<AudioNode>> getMixedAudioTrack();

protected:
    void setChildrenTransform(const sf::Transform &transform) override;

public:
    LayersPanel();

    sf::FloatRect getGlobalBounds() const override;

    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void exportTrack(const std::string& string);

};


#endif //DIZZLESTUDIOPRO_LAYERSPANEL_H
