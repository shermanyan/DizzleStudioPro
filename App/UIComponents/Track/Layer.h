//
// Created by Sherman Yan on 4/14/23.
//

#ifndef DIZZLESTUDIOPRO_LAYER_H
#define DIZZLESTUDIOPRO_LAYER_H


#include "AppComponent.h"
#include "Squircle.h"
#include "TrackLabel.h"
#include "DynamicInstrumentPanel.h"
#include "Track.h"

#include "KeyboardTrack.h"
#include "AudioTrack.h"
#include "VocalTrack.h"
#include "DrumPadTrack.h"

class Layer: public AppComponent {
private:

    static DynamicInstrumentPanel* instrumentPanel;
    static SeekBar* seekBar;

    TrackLabel label;

    Track track;


protected:
    void setChildrenTransform(const sf::Transform &transform) override;

public:
    Layer();

    void setTrackColor(const sf::Color& color);
    void setTrack(InstrumentsEnum type);
    InstrumentsEnum getTrackType() const;

    static void setInstrumentPanel(DynamicInstrumentPanel *instrumentPanel);
    static void setSeekBar(SeekBar* seekbar);

    sf::FloatRect getGlobalBounds() const override;

    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};



#endif //DIZZLESTUDIOPRO_LAYER_H
