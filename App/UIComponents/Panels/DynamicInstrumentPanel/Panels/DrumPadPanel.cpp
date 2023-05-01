//
// Created by Brandon Hargitay on 4/28/23.
//

#include "DrumPadPanel.h"
#include <iostream>
DrumPadPanel::DrumPadPanel() {
    drumPad = {BasePanel::getSize() - sf::Vector2f {60, 60}, 7};
//    Position::center(drumPad,*this);

}

void DrumPadPanel::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    BasePanel::eventHandler(window, event);

    drumPad.eventHandler(window, event);
}

void DrumPadPanel::update(const sf::RenderWindow &window) {
    BasePanel::update(window);
}

void DrumPadPanel::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    BasePanel::draw(target, states);
    states.transform *= getTransform();

    target.draw(drumPad, states);
}

void DrumPadPanel::setChildrenTransform(const sf::Transform &transform) {
    drumPad.setParentTransform(transform);
}

std::vector<AudioNode *> DrumPadPanel::getKeyPressed(const sf::RenderWindow &window) {
    return drumPad.getKeyPressed(window);
}
