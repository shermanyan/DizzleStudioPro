//
// Created by Brandon Hargitay on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_STATICVISUALIZERPANEL_H
#define DIZZLESTUDIOPRO_STATICVISUALIZERPANEL_H
#include "DynamicInstrumentPanel.h"
#include "StaticAudioVisualizer.h"
#include "SpriteImage.h"
#include "TextInput.h"

class StaticVisualizerPanel : public DynamicInstrumentPanel {
private:
    StaticAudioVisualizer visualizer;
    SpriteImage playButton;
    sf::Texture texture;
    TextInput textInput;
public:

    StaticVisualizerPanel();

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


    void setPosition(sf::Vector2f pos);

};




#endif //DIZZLESTUDIOPRO_STATICVISUALIZERPANEL_H
