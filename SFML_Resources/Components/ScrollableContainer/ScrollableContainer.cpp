//
// Created by Sherman Yan on 12/9/22.
//

#ifndef SCROLLABLECONTAINER_CPP
#define SCROLLABLECONTAINER_CPP

#include "ScrollableContainer.h"
#include <iostream>
template<class T>
int ScrollableContainer<T>::MAX_ITEMS = 10;

template<class T>
ScrollableContainer<T>::ScrollableContainer() {}

template<class T>
ScrollableContainer<T>::ScrollableContainer(ScrollEnum scrollDirection, float spacing):
scrollDirection(scrollDirection), spacing(spacing){
}

template<class T>
void ScrollableContainer<T>::scroll(float delta) {
    if (!items.empty()) {
        sf::FloatRect selfSize = getGlobalBounds();
        switch (scrollDirection) {
            case HORIZONTAL: {
                if (delta + selfSize.left <= bound.left &&
                    delta + selfSize.left + selfSize.width >= bound.width)
                    items[0]->move(delta * direction, 0);

                break;
            }
            case VERTICAL: {
                if (delta + selfSize.top <= bound.top &&
                    delta + selfSize.top + selfSize.height >= bound.height)

                    items[0]->move(0, delta * direction);

                break;
            }
            default:
                exit(10);
        }
    }
}

template<class T>
void ScrollableContainer<T>::addComponent(T *item) {

    if (items.size() <= MAX_ITEMS)
        items.push_back(item);

}

template<class T>
void ScrollableContainer<T>::reverseScrollDirection() {
    direction *= -1;
}

template<class T>
void ScrollableContainer<T>::setItemSpacing(float spacing) {
    this->spacing = spacing;
}

template<class T>
sf::FloatRect ScrollableContainer<T>::getGlobalBounds() const {
    if(!items.empty()) {
        sf::Vector2f f = getTransform().transformPoint(items.front()->getPosition());
        sf::FloatRect e = getTransform().transformRect(items.back()->getGlobalBounds());
        return {f.x, f.y, (spacing + e.width) * items.size() - spacing , e.height};
    } return {0,0,0,0};
}

template<class T>
void ScrollableContainer<T>::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    states.transform *= getTransform();
    for(auto *d:items)
        target.draw(*d,states);

}

template<class T>
void ScrollableContainer<T>::update(const sf::RenderWindow &window) {

    if(!items.empty()) {
        switch (scrollDirection) {
            case HORIZONTAL: {
                for (int i = 1; i < items.size(); i++) {
                    Position::right(*items[i], *items[i - 1], spacing);
                }
                break;
            }
            case VERTICAL: {
                for (int i = 1; i < items.size(); i++)
                    Position::bottom(*items[i], *items[i - 1], spacing);

                break;
            }
            default:
                exit(11);
        }
    }

}

template<class T>
void ScrollableContainer<T>::setPosition(float x, float y) {
    setPosition({x,y});
}

template<class T>
void ScrollableContainer<T>::setPosition(const sf::Vector2f& pos) {
    if (!items.empty())
        for (auto *i:items) {
            i->setPosition(pos);
        }
}

template<class T>
void ScrollableContainer<T>::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
   if (event.type == sf::Event::MouseWheelScrolled )
        scroll(event.mouseWheelScroll.delta * 5);

}

template<class T>
void ScrollableContainer<T>::setSpacing(float spacing) {
    ScrollableContainer::spacing = spacing;
}

template<class T>
void ScrollableContainer<T>::setSpeedMultiplier(float speedMultiplier) {
    ScrollableContainer::speedMultiplier = speedMultiplier;
}

template<class T>
void ScrollableContainer<T>::setBound(const sf::FloatRect &bound) {
    ScrollableContainer::bound = bound;
}

template<class T>
void ScrollableContainer<T>::setScrollDirection(ScrollEnum scrollDirection) {
    ScrollableContainer::scrollDirection = scrollDirection;
}

#endif