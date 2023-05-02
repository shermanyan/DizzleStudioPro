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

    addToTrackButton.setPosition(1730, 40);

}

void StaticVisualizerPanel::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    BasePanel::eventHandler(window, event);
    songInput.eventHandler(window, event);

    if (songInput.loadButonClicked(window) && !(songInput.isEmpty()))
    {
       visualizer.loadVisualizer(songInput.getSong());
        playPauseButton.setTexture(Textures::getTexture(PLAY_BUTTON));

    }

    if((event.type ==sf::Event::MouseButtonPressed && MouseEvents::isClick(getCombinedTransform().transformRect(playPauseButton.getGlobalBounds()),window)) && !(songInput.isEmpty())){
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
    songInput.update(window);

}

void StaticVisualizerPanel::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    BasePanel::draw(target, states);

    states.transform *= getTransform();

    target.draw(visualizer,states);
    target.draw(playPauseButton,states);
    target.draw(songInput,states);
    target.draw(addToTrackButton, states);

}


void StaticVisualizerPanel::setChildrenTransform(const sf::Transform &transform) {
    visualizer.setParentTransform(transform);
    songInput.setParentTransform(transform);
    addToTrackButton.setParentTransform(transform);

}

AudioNode *StaticVisualizerPanel::getNode() {
    auto node = &visualizer;
    node->duration = visualizer.buffer.getDuration().asSeconds();
    node->keyEnum = SOUND;
    return node;
}

bool StaticVisualizerPanel::getStatus(const sf::RenderWindow& window) {
    return addToTrackButton.isClick(window);
}
