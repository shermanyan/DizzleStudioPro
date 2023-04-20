//
// Created by Sherman Yan on 4/19/23.
//

#include "LayersPanel.h"

LayersPanel::LayersPanel() {
    background = {{1960, 600},20, {121,121,121}};
}

void LayersPanel::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

}

void LayersPanel::update(const sf::RenderWindow &window) {

}

void LayersPanel::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    states.transform *= getTransform();
    target.draw(background,states);
}
