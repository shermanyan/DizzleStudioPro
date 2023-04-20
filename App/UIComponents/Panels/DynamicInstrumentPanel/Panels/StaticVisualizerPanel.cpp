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
    std::cout << "Test";
    playButton.setTexture(texture);
    playButton.setSize({200,200});
}

void StaticVisualizerPanel::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    BasePanel::eventHandler(window, event);

    if(MouseEvents::isClick(playButton.getGlobalBounds(),window) ){
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
    visualizer.draw(target, states);
    target.draw(playButton);

}

void StaticVisualizerPanel::setPosition( sf::Vector2f pos) {
    BasePanel::setPosition(pos);
    pos.x = BasePanel::getGlobalBounds().left + 750;
    pos.y = BasePanel::getGlobalBounds().top + 205;
    playButton.setPosition(sf::Vector2f(BasePanel::getGlobalBounds().left + 500 , BasePanel::getGlobalBounds().top +100));
    visualizer.setPosition(pos);
}