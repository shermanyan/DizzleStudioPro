//
// Created by Sherman Yan on 4/16/23.
//

#include "Transformable.h"


sf::Transform Transformable::getParentTransform() const {
    return parentTransform;
}

sf::Transform Transformable::getCombinedTransform() const {
    return getTransform() * parentTransform;
}

void Transformable::setParentTransform(const sf::Transform &transform) {
    this->parentTransform = transform;
    setChildrenTransform(getCombinedTransform());
}

void Transformable::setChildrenTransform(const sf::Transform &transform) {
}

void Transformable::setPosition(const sf::Vector2f &pos) {
    sf::Transformable::setPosition(pos);

    setParentTransform(getTransform());
    setChildrenTransform(getTransform());
}

void Transformable::setPosition(float x, float y) {
    setPosition({x, y});
}

sf::FloatRect Transformable::getGlobalBounds() const {

}

sf::FloatRect Transformable::getLocalBounds() const {
}



