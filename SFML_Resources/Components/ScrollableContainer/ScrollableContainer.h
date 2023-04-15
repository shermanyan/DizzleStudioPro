//
// Created by Sherman Yan on 12/9/22.
//

#ifndef SCROLLABLECONTAINER_H
#define SCROLLABLECONTAINER_H

#include "AppComponent.h"
#include "ScrollEnum.h"
#include "Position.h"
template<class T>
class ScrollableContainer : public AppComponent{
private:
    static int MAX_ITEMS;
    float spacing = 30;
    std::vector<T*> items;

    int direction = 1;
    float speedMultiplier;

    sf::FloatRect bound;


    ScrollEnum scrollDirection = HORIZONTAL;
public:
    void setSpacing(float spacing);

    void setSpeedMultiplier(float speedMultiplier);

    void setBound(const sf::FloatRect &bound);

    void setScrollDirection(ScrollEnum scrollDirection);

private:
    void scroll(float delta);

public:
    ScrollableContainer();
    ScrollableContainer(ScrollEnum scrollDirection, float spacing);

    void addComponent(T* item);
    void reverseScrollDirection();
    void setItemSpacing(float spacing);

    sf::FloatRect getGlobalBounds() const;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void setPosition(float x, float y);
    void setPosition(const sf::Vector2f& pos);

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

};

#include "ScrollableContainer.cpp"

#endif //SCROLLABLECONTAINER_H
