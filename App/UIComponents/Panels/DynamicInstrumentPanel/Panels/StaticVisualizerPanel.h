//
// Created by Brandon Hargitay on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_STATICVISUALIZERPANEL_H
#define DIZZLESTUDIOPRO_STATICVISUALIZERPANEL_H
#include "StaticAudioVisualizer.h"
#include "SpriteImage.h"
#include "BasePanel.h"

class StaticVisualizerPanel : public BasePanel {
private:
    StaticAudioVisualizer visualizer;
    SpriteImage playButton;
    sf::Texture texture;
public:

    StaticVisualizerPanel();

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


    void setPosition(sf::Vector2f pos);

};




#endif //DIZZLESTUDIOPRO_STATICVISUALIZERPANEL_H
