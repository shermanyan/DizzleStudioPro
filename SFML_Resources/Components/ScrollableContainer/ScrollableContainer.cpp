//
// Created by Sherman Yan on 12/9/22.
//

#ifndef SCROLLABLECONTAINER_CPP
#define SCROLLABLECONTAINER_CPP

#include "ScrollableContainer.h"
#include <iostream>
template<class T>
int ScrollableContainer<T>::MAX_ITEMS = 25;

template<class T>
ScrollableContainer<T>::ScrollableContainer() {
}

template<class T>
ScrollableContainer<T>::ScrollableContainer(ScrollEnum scrollDirection, float spacing):
scrollDirection(scrollDirection), spacing(spacing){


}

template<class T>
void ScrollableContainer<T>::scroll(float delta, const sf::RenderWindow& window) {
    if (!items.empty()) {
        sf::FloatRect selfSize = getGlobalBounds();
        switch (scrollDirection) {
            case HORIZONTAL: {
                if (MouseEvents::isHover(selfSize,window) &&
                (selfSize.left + delta <= bound.left && selfSize.left + selfSize.width + delta >= bound.left + bound.width)) {
                    items[0].move(delta * direction,0);

                }
                break;
            }
            case VERTICAL: {
                if (MouseEvents::isHover(bound,window) &&
                (selfSize.top + delta <= bound.top && selfSize.top + selfSize.height + delta >= bound.top + bound.height)) {
                    items[0].move(0, delta * direction);
                }

                break;
            }
            default:
                exit(10);
        }
    }
}

template<class T>
void ScrollableContainer<T>::push_back(T item) {

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
        sf::FloatRect bounds = items.front().getGlobalBounds();
        bounds.width = (bounds.width * items.size()) + (10*(items.size()-1));

        return getTransform().transformRect(bounds);
    }
    return getTransform().transformRect({0,0,0,0});
}

template<class T>
sf::FloatRect ScrollableContainer<T>::getLocalBounds() const {
    sf::FloatRect bounds = getGlobalBounds();
    bounds.left = 0;
    bounds.top = 0;
    return bounds;
}

template<class T>
void ScrollableContainer<T>::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    states.transform *= getTransform();
    for(auto &d:items)
        target.draw(d,states);

}

template<class T>
void ScrollableContainer<T>::update(const sf::RenderWindow &window) {
    for (auto &i : items)
        i.update(window);

    if(!items.empty()) {
        switch (scrollDirection) {
            case HORIZONTAL: {
                for (int i = 1; i < items.size(); i++) {
                    Position::right(items[i], items[i - 1], spacing);
                }
                break;
            }
            case VERTICAL: {
                for (int i = 1; i < items.size(); i++)
                    Position::bottom(items[i], items[i - 1], spacing);
                break;
            }
            default:
                exit(11);
        }
        setChildrenTransform(getTransform());
    }
}

template<class T>
void ScrollableContainer<T>::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    for (auto &i : items)
        i.eventHandler(window,event);

    if (event.type == sf::Event::MouseWheelScrolled)
        scroll(event.mouseWheelScroll.delta * 5, window);

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

template<class T>
typename ScrollableContainer<T>::iterator ScrollableContainer<T>::begin() {
    return items.begin();
}

template<class T>
typename ScrollableContainer<T>::iterator ScrollableContainer<T>::end() {
    return items.end();
}

template<class T>
typename ScrollableContainer<T>::iterator ScrollableContainer<T>::begin() const {
    return items.begin();
}

template<class T>
typename ScrollableContainer<T>::iterator ScrollableContainer<T>::end() const {
    return items.end();
}

template<class T>
void ScrollableContainer<T>::setChildrenTransform(const sf::Transform &transform) {
    for(auto &i : items)
        i.setParentTransform(transform);

}

#endif