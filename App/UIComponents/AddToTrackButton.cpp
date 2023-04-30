//
// Created by Brandon Hargitay on 4/30/23.
//

#include "AddToTrackButton.h"

AddToTrackButton::AddToTrackButton() {
init();
}

void AddToTrackButton::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

}

void AddToTrackButton::update(const sf::RenderWindow &window) {

}

void AddToTrackButton::setParentTransform(const sf::Transform &transform) {
    Transformable::setParentTransform(transform);
}

void AddToTrackButton::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();

    target.draw(button,states);
    target.draw(text,states);
}

void AddToTrackButton::init() {
    text.setFont(Fonts::getFont(NUNITO_BOLD));
    text.setString("Add to Track");
    text.setCharacterSize(19);

    button.setSize({170,40});
    button.setRadius(7);
    button.setFillColor({121,121,121});

    Position::centerText(text,button);
}

bool AddToTrackButton::isClick(const sf::RenderWindow &window) const {
    return MouseEvents::isClick(getCombinedTransform().transformRect(button.getGlobalBounds()),window);
}

AudioNode AddToTrackButton::getAudioNode( const sf::RenderWindow &window) {

}


