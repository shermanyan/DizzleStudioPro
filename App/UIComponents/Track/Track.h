//
// Created by Sherman Yan on 4/14/23.
//

#ifndef DIZZLESTUDIOPRO_TRACK_H
#define DIZZLESTUDIOPRO_TRACK_H

#include "AppComponent.h"
#include "Squircle.h"
#include "Position.h"
#include "MouseEvents.h"
#include "AudioNode.h"
#include "DrawableAudioNode.h"
#include "SeekBar.h"

class Track: public AppComponent{
protected:
    void setFillColor(const sf::Color& color);

    std::map<float, DrawableAudioNode> audioTrack;

private:

    Squircle background, outline;

    sf::Color trackColor = sf::Color::White;
public:
    Track();

    void emplace_back(float timeStamp, AudioNode key);
    DrawableAudioNode& getLastNode();

    std::map<float, AudioNode> getAudioTrack();

    void setTrackColor(const sf::Color &trackColor);

    sf::FloatRect getGlobalBounds() const override;
    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;
    void update(const sf::RenderWindow &window) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};


#endif //DIZZLESTUDIOPRO_TRACK_H
