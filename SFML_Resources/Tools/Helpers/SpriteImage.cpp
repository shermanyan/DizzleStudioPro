//
// Created by Sherman Yan on 12/10/22.
//

#include "SpriteImage.h"

SpriteImage::SpriteImage() {
}

void SpriteImage::setSize(const sf::Vector2f& size) {
    sf::FloatRect curSize = getLocalBounds();
    sf::Vector2f scale;

    scale.x = (size.x/curSize.width);
    scale.y = (size.y/curSize.height);

    setScale(scale);
}

void SpriteImage::setWidth(float width) {
    sf::FloatRect curSize = getLocalBounds();
    float scale;

    scale = (width/curSize.width);

    setScale(scale,scale);

}
