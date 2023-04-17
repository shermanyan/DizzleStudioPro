//
// Created by Sherman Yan on 4/16/23.
//

#ifndef DIZZLESTUDIOPRO_TRANSFORMABLE_H
#define DIZZLESTUDIOPRO_TRANSFORMABLE_H
#include <SFML/Graphics.hpp>

class Transformable: public sf::Transformable {

private:
    sf::Transform transform = {};

    virtual void setChildrenTransform(const sf::Transform& transform);

public:

    virtual void setParentTransform(const sf::Transform& transform);
    sf::Transform getParentTransform() const;
    sf::Transform getCombinedTransform() const;

    virtual sf::FloatRect getGlobalBounds() const = 0;
    virtual sf::FloatRect getLocalBounds() const = 0;

    void setPosition(const sf::Vector2f & pos);
    void setPosition(float x, float y);


};


#endif //DIZZLESTUDIOPRO_TRANSFORMABLE_H
