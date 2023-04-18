//
// Created by Sherman Yan on 12/9/22.
//

#ifndef SCROLLABLECONTAINER_H
#define SCROLLABLECONTAINER_H

#include "AppComponent.h"
#include "ScrollEnum.h"
#include "Position.h"
#include "MouseEvents.h"

template<class T>
class ScrollableContainer : public AppComponent{
private:
    static int MAX_ITEMS;
    float spacing = 10;
    std::vector<T> items;

    int direction = 1;
    float speedMultiplier = 1;

    sf::FloatRect bound;

    ScrollEnum scrollDirection = HORIZONTAL;
    typedef typename std::vector<T>::iterator iterator;

    void scroll(float delta, const sf::RenderWindow& window);

    void setChildrenTransform(const sf::Transform& transform) override;
public:
    ScrollableContainer();
    ScrollableContainer(ScrollEnum scrollDirection, float spacing);

    void setSpacing(float spacing);

    void setSpeedMultiplier(float speedMultiplier);

    void setBound(const sf::FloatRect &bound);

    void setScrollDirection(ScrollEnum scrollDirection);

    void push_back(T item);
    void reverseScrollDirection();
    void setItemSpacing(float spacing);

    sf::FloatRect getGlobalBounds() const override;
    sf::FloatRect getLocalBounds() const override;

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
