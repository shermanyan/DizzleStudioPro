//
// Created by Sherman Yan on 2/17/23.
//

#ifndef CALCULATOR_SQUIRCLE_H
#define CALCULATOR_SQUIRCLE_H

#include <SFML/Graphics.hpp>

class Squircle : public sf::Drawable, public sf::Transformable {
private:

    sf::Vector2f size;
    float radii[4];

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

    Squircle(const sf::Vector2f& size, const float (&radii)[4]);

    Squircle(const sf::Vector2f &size, float radius, const sf::Color &color);

    Squircle(const sf::Vector2f &size, const float (&radii)[4], const sf::Color &color);

    void setSize(const sf::Vector2f &size);
    void setSize(float x, float y);

    sf::Vector2f getSize() const;

    void setRadius(float radius);
    void setRadius(const float (&radii)[4]);

    void setFillColor(const sf::Color &color);
    sf::Color getFillColor() const;

    float getRadius();

    sf::FloatRect getGlobalBounds() const;
    sf::FloatRect getLocalBounds() const;

};


#endif //CALCULATOR_SQUIRCLE_H
