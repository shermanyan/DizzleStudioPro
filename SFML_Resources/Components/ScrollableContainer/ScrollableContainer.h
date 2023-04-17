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
    float spacing = 10;
    std::vector<T> items;

    typedef typename std::vector<T>::iterator iterator;
    int direction = 1;
    float speedMultiplier;

    sf::FloatRect bound;

    ScrollEnum scrollDirection = HORIZONTAL;

    void scroll(float delta);

public:
    void setSpacing(float spacing);

    void setSpeedMultiplier(float speedMultiplier);

    void setBound(const sf::FloatRect &bound);

    void setScrollDirection(ScrollEnum scrollDirection);

    ScrollableContainer();
    ScrollableContainer(ScrollEnum scrollDirection, float spacing);

    void push_back(T item);
    void reverseScrollDirection();
    void setItemSpacing(float spacing);

    sf::FloatRect getGlobalBounds() const override;
    sf::FloatRect getLocalBounds() const override;

    void setPosition(const sf::Vector2f & pos);
    void setPosition(float x, float y);
    void setParentTransform(const sf::Transform& transform);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    iterator begin();
    iterator end();
    iterator begin() const;
    iterator end() const;

};

#include "ScrollableContainer.cpp"

#endif //SCROLLABLECONTAINER_H
