//
// Created by Sherman Yan on 4/14/23.
//

#include "DrumPad.h"

DrumPad::DrumPad(){

}
DrumPad::DrumPad(const sf::Vector2f &size, int numOfPads) {
    this->size = size;
    this->numOfPads = numOfPads;
    this->spacing = 15.0f;
    setupPads();
    positionPads();
    loudSound();
}

void DrumPad::setChildrenTransform(const sf::Transform &transform) {
    for (auto &p : pads)
        p.setParentTransform(transform);
}

void DrumPad::positionPads() {
    sf::Vector2f padSize = calculatePadSize();
    float totalWidth = numOfPads * padSize.x + (numOfPads - 1) * spacing;
    float leftOffset = (size.x - totalWidth) / 2;
    float topOffset = (size.y - padSize.y) / 2;

    for (int i = 0; i < numOfPads; i++) {
        float xPos = leftOffset + i * (padSize.x + spacing);
        float yPos = topOffset;
        pads[i].setPosition({xPos + 30, yPos + 30});
        pads[i].setupText(SoundKeysStrings[i+15]);
    }

}
sf::Vector2f DrumPad::calculatePadSize() const {
    float width = (size.x - (numOfPads - 1) * spacing) / numOfPads;
    float height = size.y ; // To maintain square pads and equal spacing
    return {width, height};
}

void DrumPad::setupPads() {
    sf::Vector2f padSize = calculatePadSize();
    for (int i = 0; i < numOfPads; i++){
        pads.emplace_back(Pads(padSize));
        pads[i].octave = 1;
        pads[i].keyEnum = (SoundKeys(CLAP + i));
    }
}

void DrumPad::loudSound() {
    for (auto &k : pads) {
        k.loadSound();
    }
}


void DrumPad::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();

    for(auto &p : pads)
        target.draw(p,states);
}

void DrumPad::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    for(auto &p : pads)
        p.eventHandler(window,event);
}

void DrumPad::update(const sf::RenderWindow &window) {

}

std::vector<AudioNode *> DrumPad::getKeyPressed(const sf::RenderWindow& window) {
    std::vector<AudioNode *> pressed;
    for (auto& p:pads) {
        if(p.isClick(window))
            pressed.push_back(&p);

    }
    return pressed;
}
