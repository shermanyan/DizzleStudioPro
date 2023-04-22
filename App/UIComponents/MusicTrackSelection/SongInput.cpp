//
// Created by Brandon Hargitay on 4/22/23.
//

#include "SongInput.h"

SongInput::SongInput() {
    songInput.setPosition(100, 140);
    songInput.setTextBoxFont(Fonts::getFont(NUNITO_BOLD));
    songInput.toggleBox();
    songInput.setLabelCharacterSize(30);
    songInput.setTextBoxSize({400,40});
    songInput.setString("Enter Songs File Name:");

    loadButton.setRadius(9);
    loadButton.setSize({105,33});
    loadButton.setFillColor({121,121,121});
    Position::bottom(loadButton,songInput);
    loadButton.setPosition(songInput.getPosition().x + 120,loadButton.getPosition().y);


    text.setFont(Fonts::getFont(NUNITO_BOLD));
    text.setCharacterSize(18);
    text.setString("Load");
    Position::center(text,loadButton);
    text.setPosition(text.getPosition().x, text.getPosition().y -5);

}

void SongInput::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    songInput.eventHandler(window,event);

    if(MouseEvents::isHover((loadButton.getGlobalBounds()), window) )
    {
        printf("CLICKED");
    }
}

void SongInput::update(const sf::RenderWindow &window) {
    songInput.update(window);
}

void SongInput::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();

    target.draw(songInput,states);
    target.draw(loadButton, states);
    target.draw(text,states);
}

void SongInput::setChildrenTransform(const sf::Transform &transform) {
    songInput.setParentTransform(transform);
}


