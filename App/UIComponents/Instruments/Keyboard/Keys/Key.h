//
// Created by Sherman Yan on 4/14/23.
//

#ifndef DIZZLESTUDIOPRO_KEY_H
#define DIZZLESTUDIOPRO_KEY_H


#include "AppComponent.h"
#include "Squircle.h"
#include "Position.h"
#include "MouseEvents.h"

class Key: public AppComponent {
private:
    sf::FloatRect clickableRange;

    Squircle key;
    sf::Color color;

public:
    //default constructor
    Key();
    //constructor
    //input: key size and key background color
    Key(const sf::Vector2f& size, const sf::Color& color);

    void setSize(const sf::Vector2f& size);
    sf::Vector2f getSize() const;

    void setClickableRange(const sf::FloatRect &clickableRange);

    void setRadius(float radius);
    void setRadius(const float (&radii)[4]);

    void setFillColor (const sf::Color& color);
    sf::Color getFillColor();

    bool isClick(const sf::RenderWindow& window) const;

    sf::FloatRect getGlobalBounds() const override;
    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;
    void update(const sf::RenderWindow &window) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};



#endif //DIZZLESTUDIOPRO_KEY_H
