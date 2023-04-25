//
// Created by Sherman Yan on 4/24/23.
//

#ifndef DIZZLESTUDIOPRO_DRAWABLEAUDIONODE_H
#define DIZZLESTUDIOPRO_DRAWABLEAUDIONODE_H

#include "Squircle.h"
#include "AppComponent.h"
#include "AudioNode.h"

class DrawableAudioNode: public AppComponent{
private:
    static float scale;

    Squircle box;
    float trackHeight;

    AudioNode node;

    void positionNode();
    void setSize();

public:
    DrawableAudioNode(float timeStamp, AudioNode key, const sf::Color& color, float trackHeight = 120);

    static void setDuration(int duration);

    AudioNode& getNode();

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};




#endif //DIZZLESTUDIOPRO_DRAWABLEAUDIONODE_H
