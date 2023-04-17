//
// Created by Sherman Yan on 4/16/23.
//

#ifndef DIZZLESTUDIOPRO_TRANSFORMABLE_H
#define DIZZLESTUDIOPRO_TRANSFORMABLE_H
#include <SFML/Graphics.hpp>

class Transformable: public sf::Transformable {

private:
    sf::Transform transform;

public:

    void setParentTransform(const sf::Transform& transform);
    sf::Transform getParentTransform() const;
    sf::Transform getCombinedTransform() const;

    virtual sf::FloatRect getGlobalBounds() const = 0;
    virtual sf::FloatRect getLocalBounds() const = 0;

};


#endif //DIZZLESTUDIOPRO_TRANSFORMABLE_H
