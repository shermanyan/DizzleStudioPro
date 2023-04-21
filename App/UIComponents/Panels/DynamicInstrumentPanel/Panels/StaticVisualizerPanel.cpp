//
// Created by Brandon Hargitay on 4/19/23.
//

#include <iostream>
#include "StaticVisualizerPanel.h"
#include "Textures.h"
#include "MouseEvents.h"

StaticVisualizerPanel::StaticVisualizerPanel()
: visualizer("JCole.wav", {1200,900})
{
    texture = Textures::getTexture(PLAY_BUTTON);
    playButton.setTexture(texture);
    playButton.setSize({200,200});

    Position::center(playButton,*this);
    playButton.setPosition(playButton.getPosition().x - 600 ,playButton.getPosition().y);

    Position::center(visualizer,*this);
    visualizer.setPosition(visualizer.getPosition().x +200 ,visualizer.getPosition().y + 30);
}

void StaticVisualizerPanel::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    BasePanel::eventHandler(window, event);

    if(MouseEvents::isClick(getCombinedTransform().transformRect(playButton.getGlobalBounds()),window) ){
        visualizer.eventHandler(window,event);
        if(visualizer.isPlaying){
            playButton.setTexture(Textures::getTexture(PAUSE_BUTTON));
        }else{
            playButton.setTexture(Textures::getTexture(PLAY_BUTTON));

        }
    }
}

void StaticVisualizerPanel::update(const sf::RenderWindow &window) {
    BasePanel::update(window);
    visualizer.update(window);

}

void StaticVisualizerPanel::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    BasePanel::draw(target, states);

    states.transform *= getTransform();

    target.draw(visualizer,states);
    target.draw(playButton,states);

}


void StaticVisualizerPanel::setChildrenTransform(const sf::Transform &transform) {
    visualizer.setParentTransform(transform);
}
