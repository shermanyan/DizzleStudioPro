//
// Created by Brandon Hargitay on 4/23/23.
//

#include "LayerDropDownMenu.h"
LayerDropDownMenu::LayerDropDownMenu() {
     dropDownMenu.setTexture(Textures::getTexture(DROP_DOWN_MENU));

}

void LayerDropDownMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(dropDownMenu, states);
}

sf::FloatRect LayerDropDownMenu::getGlobalBounds() const {
    return dropDownMenu.getGlobalBounds();
}

sf::FloatRect LayerDropDownMenu::getLocalBounds() const {

}

void LayerDropDownMenu::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

}

void LayerDropDownMenu::update(const sf::RenderWindow &window) {

}

void LayerDropDownMenu::setSize(sf::Vector2f size) {
    dropDownMenu.setSize(size);
}








