//
// Created by Brandon Hargitay on 4/23/23.
//

#include "LayerDropDownMenu.h"
#include "Position.h"
#include "MouseEvents.h"

LayerDropDownMenu::LayerDropDownMenu() {
    dropDownMenu.setTexture(Textures::getTexture(DROP_DOWN_MENU));
    setState(HIDDEN,true);

    for (int i = 0; i < EMPTY; ++i) {
        clickableRanges[InstrumentsEnum(i)].setTexture(Textures::getTexture(DROP_DOWN_OVERLAY));
    }
}

void LayerDropDownMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    if (!checkStates(HIDDEN)) {
        target.draw(dropDownMenu, states);
        for(auto& c: clickableRanges) {
            if(c.second.checkStates(HOVERED))
                target.draw(c.second, states);
        }
    }
}

sf::FloatRect LayerDropDownMenu::getGlobalBounds() const {
    return getTransform().transformRect(dropDownMenu.getGlobalBounds());
}

sf::FloatRect LayerDropDownMenu::getLocalBounds() const {

}

void LayerDropDownMenu::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    if (!checkStates(HIDDEN)){
        for(auto& c: clickableRanges) {
            if(event.type == sf::Event::MouseButtonPressed && MouseEvents::isClick(getCombinedTransform().transformRect(c.second.getGlobalBounds()),window))
                c.second.setState(SELECTED, true);
            if(MouseEvents::isHover(getCombinedTransform().transformRect(c.second.getGlobalBounds()),window))
                c.second.setState(HOVERED, true);
            else {
                c.second.setState(SELECTED, false);
                c.second.setState(HOVERED, false);
            }
        }
    }

}

void LayerDropDownMenu::update(const sf::RenderWindow &window) {
}

void LayerDropDownMenu::setSize(sf::Vector2f size) {
    dropDownMenu.setSize(size);

    resize();

}

void LayerDropDownMenu::setWidth(float width) {
    dropDownMenu.setWidth(width);
    resize();
}

void LayerDropDownMenu::resize() {
    for (auto i =clickableRanges.begin(); i != clickableRanges.end(); i++) {
        i->second.setWidth(dropDownMenu.getGlobalBounds().width - 20);
        if ( i == clickableRanges.begin())
            i->second.setPosition(10,10);
        else{
            Position::center(i->second,std::prev(i)->second);
            Position::bottom(i->second,std::prev(i)->second,-18);
        }
    }
}

InstrumentsEnum LayerDropDownMenu::getSelected() {
    for (auto & c:clickableRanges) {
        if(c.second.checkStates(SELECTED))
            return c.first;
    }
    return EMPTY;
}







