//
// Created by Brandon Hargitay on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_AUDIORECORDINGPANEL_H
#define DIZZLESTUDIOPRO_AUDIORECORDINGPANEL_H

#include "DynamicInstrumentPanel.h"
#include "AudioVisualizer.h"
#include "SpriteImage.h"

class AudioRecordingPanel : public DynamicInstrumentPanel{
private:
    AudioVisualizer liveRecording;
    SpriteImage button;
    sf::Texture texture;
    bool isRecording = false;
public:

    AudioRecordingPanel();

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void setPosition(sf::Vector2f pos);

    void setScale(float x, float y);
};


#endif //DIZZLESTUDIOPRO_AUDIORECORDINGPANEL_H
