//
// Created by Sherman Yan on 4/24/23.
//

#ifndef DIZZLESTUDIOPRO_DRAWABLEAUDIONODE_H
#define DIZZLESTUDIOPRO_DRAWABLEAUDIONODE_H

#include "Squircle.h"
#include "AppComponent.h"
#include "AudioNode.h"
#include "StudioStatics.h"

class DrawableAudioNode: public AppComponent{
private:
    static float scale;

    AudioNode node;

    Squircle box;
    float trackHeight;

    void positionNode();
    void setSize();

public:
    DrawableAudioNode(float timeStamp,const AudioNode& key, const sf::Color& color, float trackHeight = 120);

    static void setDurationScale(int duration);

    AudioNode getNode() const;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};




#endif //DIZZLESTUDIOPRO_DRAWABLEAUDIONODE_H
