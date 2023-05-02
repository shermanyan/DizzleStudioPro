//
// Created by Sherman Yan on 4/23/23.
//

#ifndef DIZZLESTUDIOPRO_KEYBOARDTRACK_H
#define DIZZLESTUDIOPRO_KEYBOARDTRACK_H

#include "StudioStatics.h"
#include "Track.h"
#include "KeyboardPanel.h"

class KeyboardTrack :public Track{
private:
    std::vector<std::map<SoundKeys,DrawableAudioNode*>> nodes;
public:
    KeyboardTrack();

    void update(const sf::RenderWindow &window) override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;


};


#endif //DIZZLESTUDIOPRO_KEYBOARDTRACK_H
