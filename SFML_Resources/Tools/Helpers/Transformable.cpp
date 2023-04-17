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
}
