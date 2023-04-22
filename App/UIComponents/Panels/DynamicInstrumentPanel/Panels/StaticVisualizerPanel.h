//
// Created by Brandon Hargitay on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_STATICVISUALIZERPANEL_H
#define DIZZLESTUDIOPRO_STATICVISUALIZERPANEL_H
#include "StaticAudioVisualizer.h"
#include "SpriteImage.h"
#include "BasePanel.h"
#include "TextInput.h"

class StaticVisualizerPanel : public BasePanel {
private:
    StaticAudioVisualizer visualizer;
    SpriteImage playPauseButton;
    sf::Texture texture;
    TextInput songNameInput;
public:

    StaticVisualizerPanel();

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;



protected:
    void setChildrenTransform(const sf::Transform &transform) override;

};




<<<<<<< HEAD
#endif //DIZZLESTUDIOPRO_STATICVISUALIZERPANEL_H
=======
#endif //DIZZLESTUDIOPRO_STATICVISUALIZERPANEL_H
>>>>>>> Sherman
