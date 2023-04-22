//
// Created by Sherman Yan on 4/14/23.
//

#include "OctaveKeys.h"
#include <iostream>

OctaveKeys::OctaveKeys(): OctaveKeys({760,347}, { {94, 94, 94},{36, 36, 36}}) {

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
        k.second.setFillColor(color);
    }
}

void OctaveKeys::setWhiteKeyColor(const sf::Color &color) {
    for (auto &k :whiteKeys) {
        k.second.setFillColor(color);
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
    sf::FloatRect bounds = whiteKeys.at(C).getGlobalBounds();

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
    for (auto &k :blackKeys) {
        k.second.eventHandler(window, event);
    }
    for (auto &k :whiteKeys){
        k.second.eventHandler(window,event);
    }

}

void OctaveKeys::update(const sf::RenderWindow &window) {
    for (auto &k :blackKeys)
        k.second.update(window);
    for (auto &k :whiteKeys)
        k.second.update(window);
}

void OctaveKeys::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (auto &k :whiteKeys)
        target.draw(k.second,states);
    for (auto &k :blackKeys)
        target.draw(k.second,states);

}

void OctaveKeys::setupKeys() {

    setupBlackKeys();
    setUpWhiteKeys();
    setFillColors(keyColors);
    positionKeys();
}

void OctaveKeys::setUpWhiteKeys() {
    for (int i = 0; i < 7; ++i) {
        whiteKeys[SoundKeys(C + i)] = {};
        whiteKeys.at(SoundKeys(C + i)).setRadius({10, 10, 10, 10});
        whiteKeys.at(SoundKeys(C + i)).setKeyType(SoundKeys(C + i));

    }
}

void OctaveKeys::setupBlackKeys() {

    for (int i = 0; i < 5; ++i) {
        blackKeys[SoundKeys(Cs + i)] = {};
        blackKeys.at(SoundKeys(Cs + i)).setRadius({5, 5, 10, 10});
        blackKeys.at(SoundKeys(Cs + i)).setKeyType(SoundKeys(Cs + i));
    }
}

void OctaveKeys::setWhiteKeysSize() {
    float keyWidth = ((size.x - (spacing * 6)) /7) ;
    for (auto &k :whiteKeys) {
        k.second.setSize({keyWidth, size.y});
        k.second.setClickableRange({0,size.y * blackKeySizeRatio.y ,keyWidth,size.y - (size.y * blackKeySizeRatio.y)});
    }
}

void OctaveKeys::setBlackKeysSize() {

    for (auto &k :blackKeys)
        k.second.setSize({whiteKeys.at(C).getSize().x * blackKeySizeRatio.x, size.y * blackKeySizeRatio.y});
}

void OctaveKeys::positionKeys() {
    //position whites keys
    //position first white key
    //position the rest of the keys
    for (auto i = std::next(whiteKeys.begin()); i != whiteKeys.end(); i++) {
        Position::center((*i).second,(*std::prev(i)).second);
        Position::right((*i).second,(*std::prev(i)).second,spacing);
    }

//    position black keys
    for (int i = 0; i < blackKeys.size() ; ++i) {
        auto whiteKeyIndex = SoundKeys(C + (i > 1 ? i + 2 : i + 1));
        auto blackKeyIndex = SoundKeys(Cs + i);

        Position::alignTop(blackKeys[blackKeyIndex],whiteKeys[whiteKeyIndex]);
        Position::alignLeft(blackKeys[blackKeyIndex],whiteKeys[whiteKeyIndex]);

        blackKeys[blackKeyIndex].setPosition(whiteKeys[whiteKeyIndex].getPosition().x
                                                - (spacing / 2) - (blackKeys[blackKeyIndex].getSize().x/2)
                                                , blackKeys[blackKeyIndex].getPosition().y);
    }

    setChildrenTransform(getTransform());

}

void OctaveKeys::refresh() {
    setWhiteKeysSize();
    setBlackKeysSize();
    positionKeys();
}


void OctaveKeys::setChildrenTransform(const sf::Transform &transform) {

    for (auto &k :whiteKeys)
        k.second.setParentTransform(transform);
    for (auto &k :blackKeys)
        k.second.setParentTransform(transform);
}

float OctaveKeys::getKeySpacing() const {
    return spacing;
}

SoundKeys OctaveKeys::getKeyPress(const sf::RenderWindow& window) const {
    SoundKeys keyPressed = NULL_KEY;

    for (auto &k: whiteKeys) {
        if (k.second.isClick(window))
            keyPressed = k.first;
    }
    if (keyPressed == NULL_KEY) {
        for (auto &k: blackKeys) {
            if (k.second.isClick(window))
                keyPressed = k.first;
        }
    }

    return keyPressed;
}


