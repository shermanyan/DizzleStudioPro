//
// Created by Brandon Hargitay on 4/22/23.
//

#include "SongInput.h"

SongInput::SongInput() {
    songInput.setPosition(100, 165);
    songInput.setTextBoxFont(Fonts::getFont(NUNITO_BOLD));
    songInput.toggleBox();
    songInput.setLabelCharacterSize(30);
    songInput.setTextBoxSize({400,40});
    songInput.setString("Enter File Name");

    loadButton.setRadius(9);
    loadButton.setSize({105,33});
    loadButton.setFillColor({121,121,121});
    Position::bottom(loadButton,songInput);
    loadButton.setPosition(songInput.getPosition().x + 120,loadButton.getPosition().y + 12);


    text.setFont(Fonts::getFont(NUNITO_BOLD));
    text.setCharacterSize(18);
    text.setString("Load");
    Position::center(text,loadButton);
    text.setPosition(text.getPosition().x, text.getPosition().y -5);

    inner.setRadius(8);
    inner.setSize({390,40});
    inner.setFillColor({36, 36, 36});
    Position::center(inner,songInput);
    inner.setPosition({inner.getPosition().x -15, inner.getPosition().y- 5});


    outer.setRadius(8);
    outer.setSize({402,52});
    outer.setFillColor({94, 94, 94});
    Position::center(outer,songInput);
    outer.setPosition({inner.getPosition().x -6, inner.getPosition().y- 6});
}

void SongInput::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    songInput.eventHandler(window,event);


}

void SongInput::update(const sf::RenderWindow &window) {
    songInput.update(window);
}

void SongInput::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(outer, states);
    target.draw(inner, states);
    target.draw(songInput,states);
    target.draw(loadButton, states);
    target.draw(text,states);
}

void SongInput::setChildrenTransform(const sf::Transform &transform) {
    songInput.setParentTransform(transform);
}

std::string SongInput::getSong() {
    return songInput.getString();
}


