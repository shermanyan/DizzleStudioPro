//
// Created by Sherman Yan on 4/16/23.
//

#include "Transformable.h"


sf::Transform Transformable::getParentTransform() const {
    return transform;
}

sf::Transform Transformable::getCombinedTransform() const {
    return getTransform() * transform;
}

void Transformable::setParentTransform(const sf::Transform &transform) {
    this->transform = transform;
    setChildrenTransform(getCombinedTransform());

}

void Transformable::setChildrenTransform(const sf::Transform &transform) {
}

void Transformable::setPosition(const sf::Vector2f &pos) {
    sf::Transformable::setPosition(pos);

    sf::Transform trans = getTransform();
    setParentTransform(trans);
    setChildrenTransform(trans);
}

void Transformable::setPosition(float x, float y) {
    setPosition({x, y});
}



