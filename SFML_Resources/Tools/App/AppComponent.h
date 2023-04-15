//
// Created by Sherman Yan on 11/17/22.
//

#ifndef APPCOMPONENT_H
#define APPCOMPONENT_H
#include <SFML/Graphics.hpp>
#include "EventHandleable.h"
#include "Updatable.h"

class AppComponent: public EventHandleable, public sf::Drawable, public sf::Transformable, public Updatable{

};


#endif //APPCOMPONENT_H
