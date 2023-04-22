//
// Created by Brandon Hargitay on 4/19/23.
//

#include "StaticVisualizerPanel.h"
#include "Textures.h"
#include "MouseEvents.h"

StaticVisualizerPanel::StaticVisualizerPanel()
: visualizer("Kenderick.wav", {1200,900}) {
    texture = Textures::getTexture(PLAY_BUTTON);
    playPauseButton.setTexture(texture);
    playPauseButton.setSize({200, 200});

    Position::center(playPauseButton, *this);
    playPauseButton.setPosition(playPauseButton.getPosition().x - 350, playPauseButton.getPosition().y);

    Position::center(visualizer, *this);
    visualizer.setPosition(visualizer.getPosition().x + 385, visualizer.getPosition().y);

}

void StaticVisualizerPanel::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    BasePanel::eventHandler(window, event);
    songinput.eventHandler(window, event);

    if(MouseEvents::isClick(getCombinedTransform().transformRect(playPauseButton.getGlobalBounds()),window) ){
        visualizer.eventHandler(window,event);
        if(visualizer.isPlaying){
            playPauseButton.setTexture(Textures::getTexture(PAUSE_BUTTON));
        }else{
            playPauseButton.setTexture(Textures::getTexture(PLAY_BUTTON));

        }
    }


}

void StaticVisualizerPanel::update(const sf::RenderWindow &window) {
    BasePanel::update(window);
    visualizer.update(window);
    songinput.update(window);
}

void StaticVisualizerPanel::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    BasePanel::draw(target, states);

    states.transform *= getTransform();

    target.draw(visualizer,states);
    target.draw(playPauseButton,states);
    target.draw(songinput,states);

}


void StaticVisualizerPanel::setChildrenTransform(const sf::Transform &transform) {
    visualizer.setParentTransform(transform);
    songinput.setParentTransform(transform);
}