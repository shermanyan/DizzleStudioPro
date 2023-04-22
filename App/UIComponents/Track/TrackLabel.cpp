//
// Created by Sherman Yan on 4/14/23.
//

#include "TrackLabel.h"

TrackLabel::TrackLabel():
        TrackLabel({380, 120}, sf::Color::White) {}

TrackLabel::TrackLabel(const sf::Color &labelColor, PanelTypeEnum type):
        TrackLabel({380, 120}, labelColor, type) {}

TrackLabel::TrackLabel(const sf::Vector2f &size, const sf::Color &labelColor, PanelTypeEnum type) {
    setTrack(type);
    setSize(size);
    setTrackColor(labelColor);
    label.setRadius({0,0,10,10});
}

void TrackLabel::setSize(const sf::Vector2f &size) {
    labelImg.setSize({size.x, size.y * .8f});
    label.setSize(size.x,size.y * .2f);
    Position::bottom(label,labelImg);
}

void TrackLabel::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    if(MouseEvents::isClick(getCombinedTransform().transformRect(getGlobalBounds()),window))
        label.setFillColor(trackColor * sf::Color{10,10,10});
    else
        label.setFillColor(trackColor);


}

void TrackLabel::update(const sf::RenderWindow &window) {

}

void TrackLabel::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(labelImg,states);
    target.draw(label,states);

}

void TrackLabel::setTrack(PanelTypeEnum type) {
    trackType = type;

    switch (type) {
        case KEYBOARD: {
            labelImg.setTexture(Textures::getTexture(KEYBOARD_LABEL));
            break;
        }
        case AUDIO: {
            labelImg.setTexture(Textures::getTexture(AUDIO_LABEL));
            break;
        }
        case VOCAL: {
            labelImg.setTexture(Textures::getTexture(VOCAL_LABEL));
            break;
        }
        case DRUMPAD: {
            labelImg.setTexture(Textures::getTexture(DRUMPAD_LABEL));
            break;
        }
        case EMPTY_PANEL: {
            labelImg.setTexture(Textures::getTexture(EMPTY_LABEL));
            break;
        }
    }

    labelImg.setWidth(label.getSize().x);
}

sf::FloatRect TrackLabel::getGlobalBounds() const {
    sf::FloatRect bounds = labelImg.getGlobalBounds(), lB = label.getGlobalBounds();
    bounds.height += lB.height;

    return getTransform().transformRect(bounds);
}

sf::FloatRect TrackLabel::getLocalBounds() const {
    sf::FloatRect bounds = getGlobalBounds();

    bounds.left = 0;
    bounds.top = 0;

    return bounds;
}

sf::Color TrackLabel::getTrackColor() const {
    return trackColor;
}

void TrackLabel::setTrackColor(const sf::Color &trackColor) {
    TrackLabel::trackColor = trackColor;
    label.setFillColor(trackColor);
}

PanelTypeEnum TrackLabel::getTrackType() const {
    return trackType;
}







