//
// Created by Sherman Yan on 4/14/23.
//

#include "Pads.h"
#include <iostream>

Pads::Pads() : Pads({200,200}) {
    pad.setRadius(10);
    pad.setFillColor({36, 36, 36});
}
Pads::Pads(const sf::Vector2f &size) {
//    AppComponent::setState(PLAY, false);
    setSize(size);
    pad.setRadius(10);
    pad.setFillColor({36, 36, 36});
}


//void Pads::setPosition(const sf::Vector2f &position) { // New function to set position
//    pad.setPosition(position);
//}

bool Pads::isClick(const sf::RenderWindow &window) const {
    return MouseEvents::isClick(getCombinedTransform().transformRect(pad.getGlobalBounds()),window);
}



void Pads::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();

    target.draw(pad, states);
    target.draw(text, states);
}

void Pads::setSize(const sf::Vector2f &size) {
    pad.setSize(size);
}

void Pads::getSize() {
    pad.getSize();
}

void Pads::loadSound() {
    setBuffer(Sounds::getSound(*this));
    duration = buffer.getDuration().asSeconds();
}

sf::FloatRect Pads::getGlobalBounds() const {
    return getTransform().transformRect(pad.getGlobalBounds());
}

sf::FloatRect Pads::getLocalBounds() const {
    return pad.getLocalBounds();
}

AudioNode Pads::getKeyType() const {
    return {octave,keyEnum};
}

void Pads::setupText(const std::string &string) {
    text.setFont(Fonts::getFont(NUNITO_BOLD));
    text.setFillColor({185, 185, 185});
    text.setString(string);
    Position::centerText(text,pad);
}

void Pads::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    if(isClick(window)){
        pad.setFillColor(sf::Color{36, 36, 36} + sf::Color{25,25,25});
        play();
    }else{
        pad.setFillColor(sf::Color{36, 36, 36});
    }


}

void Pads::update(const sf::RenderWindow &window) {

}





