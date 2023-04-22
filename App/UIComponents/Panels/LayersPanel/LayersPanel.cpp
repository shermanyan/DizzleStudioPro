//
// Created by Sherman Yan on 4/19/23.
//

#include "LayersPanel.h"

void LayersPanel::setChildrenTransform(const sf::Transform &transform) {
    for (auto&l:layers) {
        l.setParentTransform(transform);
    }
}

LayersPanel::LayersPanel() {
    background = {{1960, 600},20, {121,121,121}};

    for (int i = 0; i < 4; ++i) {
        layers.emplace_back();
        layers.back().setTrackColor(trackColors[i]);
    }

    layers.front().setPosition(20,70);
    for (int i = 1; i < layers.size(); i++) {
        Position::center(layers[i],layers[i-1]);
        Position::bottom(layers[i],layers[i-1],10);
    }

    layers[1].setTrack(KEYBOARD);
    layers[0].setTrack(AUDIO);

}

void LayersPanel::setInstrumentPanel(DynamicInstrumentPanel *instrumentPanel) {

    this->instrumentPanel = instrumentPanel;

    for (auto&l:layers) {
        l.setInstrumentPanel(instrumentPanel);
    }
}

void LayersPanel::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

    for (auto&l:layers) {
        l.eventHandler(window,event);

        if (event.MouseButtonPressed && MouseEvents::isClick(getTransform().transformRect(l.getGlobalBounds()), window)) {
            instrumentPanel->setActivePanel(l.getTrackType());
        }
    }

}



void LayersPanel::update(const sf::RenderWindow &window) {
    for (auto&l:layers) {
        l.update(window);
    }
}

void LayersPanel::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(background,states);

    for (auto&l:layers) {
        target.draw(l,states);
    }

}
