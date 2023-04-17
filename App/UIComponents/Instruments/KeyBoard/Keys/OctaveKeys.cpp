//
// Created by Sherman Yan on 4/14/23.
//

#include "OctaveKeys.h"
#include <iostream>

OctaveKeys::OctaveKeys(): OctaveKeys({760,347}, {{36, 36, 36}, {94, 94, 94}}) {

}
OctaveKeys::OctaveKeys(const sf::Vector2<sf::Color> &keyColors): OctaveKeys({760,347},keyColors) {
}

OctaveKeys::OctaveKeys(const sf::Vector2f &size, const sf::Vector2<sf::Color> &keyColors) {
    this->size = size;
    this->keyColors = keyColors;

    setupKeys();
    refresh();
}

void OctaveKeys::setSize(const sf::Vector2f &size) {
    this->size = size;
    refresh();
}

void OctaveKeys::setFillColors(const sf::Vector2<sf::Color> &keyColors) {

    this->keyColors = keyColors;
    setBlackKeyColor(keyColors.x);
    setWhiteKeyColor(keyColors.y);
}

void OctaveKeys::setBlackKeyColor(const sf::Color &color) {
    for (auto &k :blackKeys) {
        k.setFillColor(color);
    }
}

void OctaveKeys::setWhiteKeyColor(const sf::Color &color) {
    for (auto &k :whiteKeys) {
        k.setFillColor(color);
    }
}

void OctaveKeys::setKeySpacing(float spacing) {

    //set new spacing
    this->spacing = spacing;
    //refresh pos
    refresh();
}

sf::FloatRect OctaveKeys::getGlobalBounds() const {
    //get bounds of first key
    sf::FloatRect bounds = whiteKeys.front().getGlobalBounds();

    //multiply width by 7 to get full width and add 5 spacings
    bounds.width = (bounds.width * 7) + (spacing * 6);
    return getTransform().transformRect(bounds);
}

sf::FloatRect OctaveKeys::getLocalBounds() const {
    //get global bounds
    sf::FloatRect bounds = getGlobalBounds();
    //remove x and y pos
    bounds.left = 0;
    bounds.top = 0;

    return bounds;
}

void OctaveKeys::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    for (auto &k :blackKeys)
        k.eventHandler(window,event);
    for (auto &k :whiteKeys)
        k.eventHandler(window,event);

}

void OctaveKeys::update(const sf::RenderWindow &window) {
    for (auto &k :blackKeys)
        k.update(window);
    for (auto &k :whiteKeys)
        k.update(window);
}

void OctaveKeys::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (auto &k :whiteKeys)
        target.draw(k,states);
    for (auto &k :blackKeys)
        target.draw(k,states);

}

void OctaveKeys::setupKeys() {

    setupBlackKeys();
    setUpWhiteKeys();
    setFillColors(keyColors);
    positionKeys();
}

void OctaveKeys::setUpWhiteKeys() {
    for (int i = 0; i < 7; ++i) {
        whiteKeys.emplace_back();
        whiteKeys.back().setRadius({10,10,10,10});
    }
}

void OctaveKeys::setupBlackKeys() {

    for (int i = 0; i < 5; ++i) {
        blackKeys.emplace_back();
        blackKeys.back().setRadius({5,5,10,10});
    }
}

void OctaveKeys::setWhiteKeysSize() {
    float keyWidth = ((size.x - (spacing/6))/7) ;
    for (auto &k :whiteKeys) {
        k.setSize({keyWidth, size.y});
        k.setClickableRange({0,size.y * blackKeySizeRatio.y ,keyWidth,size.y - (size.y * blackKeySizeRatio.y)});
    }

}

void OctaveKeys::setBlackKeysSize() {

    for (auto &k :blackKeys)
        k.setSize({whiteKeys.front().getSize().x * blackKeySizeRatio.x, whiteKeys.front().getSize().y * blackKeySizeRatio.y});
}

void OctaveKeys::positionKeys() {
    //position whites keys
    //position first white key
    //position the rest of the keys
    for (auto i = std::next(whiteKeys.begin()); i != whiteKeys.end(); i++) {
        Position::center(*i,*std::prev(i));
        Position::right(*i,*std::prev(i),spacing);
    }

//    position black keys
    for (int i = 0; i < blackKeys.size() ; ++i) {
        int whiteKeyIndex = i > 1? i+2: i+1;
        Position::center(blackKeys[i],whiteKeys[whiteKeyIndex]);

        Position::alignTop(blackKeys[i],whiteKeys[whiteKeyIndex]);
        Position::alignLeft(blackKeys[i],whiteKeys[whiteKeyIndex]);

        blackKeys[i].setPosition(whiteKeys[whiteKeyIndex].getPosition().x - (spacing / 2) - (blackKeys[i].getSize().x/2), blackKeys[i].getPosition().y);
    }

}

void OctaveKeys::refresh() {
    setWhiteKeysSize();
    setBlackKeysSize();
    positionKeys();
}

void OctaveKeys::setPosition(const sf::Vector2f &pos) {
    Transformable::setPosition(pos);
    setParentTransform(getTransform());

}

void OctaveKeys::setPosition(float x, float y) {
    setPosition({x,y});
}

void OctaveKeys::setParentTransform(const sf::Transform& transform) {

    Transformable::setParentTransform(transform);

    for (auto &k :blackKeys)
        k.setParentTransform(transform);
    for (auto &k :whiteKeys)
        k.setParentTransform(transform);
}
