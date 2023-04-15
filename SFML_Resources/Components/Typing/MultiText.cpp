//
// Created by Sherman Yan on 3/5/23.
//

#include "MultiText.h"
#include <iostream>

void MultiText::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    std::list<Letter>::iterator i;
    for (auto& l : text) {
        target.draw(l,states);
    }
}
MultiText::MultiText() {

}

MultiText::MultiText(const std::string &string) {
    for(auto c: string)
        addCharacter(c);
}

void MultiText::addCharacter(char c) {
    letter.setString(std::string(1,c));
    text.push_back(letter);
//
//    if (text.size() > 1) {
//        sf::FloatRect prevPos = std::prev(text.end(),2)->getGlobalBounds();
//        text.back().setPosition(prevPos.left + prevPos.width + std::prev(text.end(),2)->getLetterSpacing(),0);
//    }
}

void MultiText::pop_back() {
    if (!text.empty())
        text.pop_back();
}

void MultiText::pop_front() {
    if (!text.empty())
        text.pop_front();
}

void MultiText::push_front(Letter letter) {
    text.push_front(letter);
}

Letter *MultiText::front() {
    return &text.front();
}

Letter *MultiText::back() {
    return &text.back();
}

void MultiText::clear() {
    text.clear();
}

void MultiText::setString(const std::string &string) {

    text.clear();
    for(auto c: string)
        addCharacter(c);

}

std::string MultiText::getString() {

    std::string s;
    for (auto& l : text) {
        s += l.getString();
    }
    return s;
}

void MultiText::setCharacterSize(unsigned int size) {
    letter.setCharacterSize(size);
}


unsigned int MultiText::getCharacterSize() {
    return letter.getCharacterSize();
}

void MultiText::setFillColor(const sf::Color &color) {
    letter.setFillColor(color);
}

void MultiText::setFillColor(const sf::Color &color, int index, int length) {

    auto it = text.begin();
    for (int i = 0 ;i < index; i++)
        it++;
    for (int i = 0; i < length; ++i) {
        it++->setFillColor(color);
    }
}


void MultiText::setFont(const sf::Font &font) {
    letter.setFont(font);
}

sf::FloatRect MultiText::getGlobalBounds() const {
    if (!text.empty()) {
        sf::FloatRect bounds;
        bounds.top = text.front().getPosition().x;
        bounds.left = text.front().getPosition().y;
        bounds.height = text.back().getGlobalBounds().height;
        bounds.width = text.back().getGlobalBounds().left + text.back().getGlobalBounds().width +
                       text.back().getLetterSpacing();
        return getTransform().transformRect(bounds);
    } else
        return getTransform().transformRect({0,0,0,0});
}

sf::FloatRect MultiText::getLocalBounds() const {
    if (!text.empty()) {
        sf::FloatRect bounds;
        bounds.top = 0;
        bounds.left = 0;
        bounds.height = text.back().getGlobalBounds().height;
        bounds.width = text.back().getGlobalBounds().left + text.back().getGlobalBounds().width +
                       text.back().getLetterSpacing();

        return getTransform().transformRect(bounds);
    } else
        return getTransform().transformRect({0,0,0,0});

}

int MultiText::length() {
    return text.size();
}

void MultiText::updatePosition() {
    text.begin()->setPosition(0,0);

    for (auto it = std::next(text.begin()) ; it != text.end(); it++) {
        sf::FloatRect prevPos = std::prev(it)->getGlobalBounds();
        it->setPosition(prevPos.left + prevPos.width + std::prev(it)->getLetterSpacing(), 0);
    }
}

