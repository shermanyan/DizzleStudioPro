//
// Created by Brandon Hargitay on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_AUDIORECORDINGPANEL_H
#define DIZZLESTUDIOPRO_AUDIORECORDINGPANEL_H

#include "AudioVisualizer.h"
#include "SpriteImage.h"
#include "BasePanel.h"
#include "Clock.h"
#include "Textures.h"
#include "MouseEvents.h"
#include "Fonts.h"
#include "FloatToStringNoTrailingZeros.h"

class AudioRecordingPanel : public BasePanel{
private:
    AudioVisualizer liveRecording;
    SpriteImage button;
    sf::Texture texture;
    bool isRecording = false;
    bool isPlaying = false;
    sf::Text clockText;
    Clock clock;
    void updateClockText();
    void handleButtonClick();

public:

    AudioRecordingPanel();

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;



protected:
    void setChildrenTransform(const sf::Transform &transform) override;
};


#endif //DIZZLESTUDIOPRO_AUDIORECORDINGPANEL_H
