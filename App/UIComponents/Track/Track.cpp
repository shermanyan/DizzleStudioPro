//
// Created by Sherman Yan on 4/14/23.
//

#include "Track.h"

Track::Track() {

    background = {{1530, 120},10,{36,41,46}};


}
void Track::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

}

void Track::update(const sf::RenderWindow &window) {

}

void Track::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();

    target.draw(background,states);
}

sf::FloatRect Track::getGlobalBounds() const {
    return getTransform().transformRect(background.getGlobalBounds());
}

sf::FloatRect Track::getLocalBounds() const {
    return background.getLocalBounds();
}


