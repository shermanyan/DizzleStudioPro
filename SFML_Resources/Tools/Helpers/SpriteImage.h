//
// Created by Sherman Yan on 12/10/22.
//

#ifndef FINALPROJECT_SPRITEIMAGE_H
#define FINALPROJECT_SPRITEIMAGE_H

#include "SFML/Graphics.hpp"
#include "States.h"

class SpriteImage : public sf::Sprite, public States{
private:

public:
    SpriteImage();
    void setSize(const sf::Vector2f& size);
    void setWidth(float width);

};


#endif //FINALPROJECT_SPRITEIMAGE_H
