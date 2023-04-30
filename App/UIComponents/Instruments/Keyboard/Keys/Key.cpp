//
// Created by Sherman Yan on 4/14/23.
//

#include "Key.h"

//Default Constructor
//Size: 0,0
//Color: white
Key::Key(): Key({0,0}, sf::Color::White) {
}

Key::Key(const sf::Vector2f &size, const sf::Color &color) {
    AppComponent::setState(PLAY, false);
    //set key size
    setSize(size);
    //set default clickable range (full key size)
    setClickableRange({0, 0, size.x, size.y});
    //set key background color
    setFillColor(color);
}


void Key::setSize(const sf::Vector2f &size) {
    key.setSize(size);
    setClickableRange({0, 0, size.x, size.y});
}

sf::Vector2f Key::getSize() const {
    return key.getSize();
}

void Key::setFillColor(const sf::Color &color) {
    this->color = color;
    key.setFillColor(color);
}

void Key::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

    if(isClick(window)){
        key.setFillColor(color + sf::Color{25,25,25});
    }else{
        setFillColor(color);
    }

    if (isClick(window) && !AudioNode::checkStates(PLAY)) {
        AudioNode::setState(PLAY, true);
        sound.play();
    }
    else if(!isClick(window) && AudioNode::checkStates(PLAY)) {
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
            sound.stop();
        AudioNode::setState(PLAY, false);
    }
}

void Key::loadSound() {
    sound.setBuffer(Sounds::getSound(*this));
}

void Key::update(const sf::RenderWindow &window) {
}

sf::FloatRect Key::getGlobalBounds() const {
    return getTransform().transformRect(key.getGlobalBounds());
}

sf::FloatRect Key::getLocalBounds() const {
    return key.getLocalBounds();
}

void Key::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(key,states);
}

sf::Color Key::getFillColor() {
    return key.getFillColor();
}

void Key::setClickableRange(const sf::FloatRect &clickableRange) {
    this->clickableRange = clickableRange;
}

void Key::setRadius(float radius) {
    key.setRadius(radius);
}

void Key::setRadius(const float (&radii)[4]) {
    key.setRadius(radii);
}

AudioNode Key::getKeyType() const{
    return *this;
}


bool Key::isClick(const sf::RenderWindow &window) const {
    return MouseEvents::isClick(getCombinedTransform().transformRect(clickableRange),window)
            || KeyboardKeyMap::isKeyBoardPress(keyEnum,octave);
}




