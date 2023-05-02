//
// Created by Brandon Hargitay on 4/23/23.
//

#include "LayerDropDownMenu.h"
LayerDropDownMenu::LayerDropDownMenu() {
     dropDownMenu.setTexture(Textures::getTexture(DROP_DOWN_MENU));

    setState(HIDDEN,true);
}

void LayerDropDownMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    if (!checkStates(HIDDEN))
        target.draw(dropDownMenu, states);
}

sf::FloatRect LayerDropDownMenu::getGlobalBounds() const {
    return dropDownMenu.getGlobalBounds();
}

sf::FloatRect LayerDropDownMenu::getLocalBounds() const {

}

void LayerDropDownMenu::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    if (!checkStates(HIDDEN)){

    }

}

void LayerDropDownMenu::update(const sf::RenderWindow &window) {
    if (!checkStates(HIDDEN)){

    }
}

void LayerDropDownMenu::setSize(sf::Vector2f size) {
    dropDownMenu.setSize(size);
}

void LayerDropDownMenu::setWidth(float width) {
    dropDownMenu.setWidth(width);

}








