//
// Created by Sherman Yan on 4/19/23.
//

#include "EmptyPanel.h"

EmptyPanel::EmptyPanel(): BasePanel{} {

    text.setFont(Fonts::getFont(NUNITO_BOLD));
    text.setString("No track selected");
    text.setCharacterSize(25);
    text.setFillColor({185,185,185});

    text.setPosition(1000,1000);
    Position::centerText(text,*this);
}

void EmptyPanel::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    BasePanel::draw(target, states);
    states.transform *= getTransform();
    target.draw(text,states);

}

