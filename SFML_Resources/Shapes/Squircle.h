//
// Created by Sherman Yan on 2/17/23.
//

#ifndef CALCULATOR_SQUIRCLE_H
#define CALCULATOR_SQUIRCLE_H

#include <SFML/Graphics.hpp>

class Squircle : public sf::Drawable, public sf::Transformable {
private:

    sf::Vector2f size;
    float radius;

    sf::CircleShape corners[4];
    sf::ConvexShape body;

    void setupCorners();

    void setupBody();

    void refresh();

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    Squircle();

    Squircle(const sf::Vector2f &size, float radius);

    Squircle(const sf::Vector2f &size, float radius, const sf::Color &color);


    void setSize(const sf::Vector2f &size);

    void setSize(float x, float y);

    void setRadius(float radius);

    void setFillColor(const sf::Color &color);

    float getRadius();

    sf::Vector2f getSize();

    sf::FloatRect getGlobalBounds() const;

    sf::FloatRect getLocalBounds() const;

};


#endif //CALCULATOR_SQUIRCLE_H
