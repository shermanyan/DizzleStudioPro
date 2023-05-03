//
// Created by Sherman Yan on 5/3/23.
//

#ifndef DIZZLESTUDIOPRO_AUDIOPLAYER_H
#define DIZZLESTUDIOPRO_AUDIOPLAYER_H

#include "AppComponent.h"
#include "StaticVisualizerPanel.h"

class AudioPlayer: public AppComponent{
private:

    StaticVisualizerPanel visualizer;

public:
    AudioPlayer();

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;
    void update(const sf::RenderWindow &window) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


};


#endif //DIZZLESTUDIOPRO_AUDIOPLAYER_H
