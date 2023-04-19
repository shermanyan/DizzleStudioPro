//
// Created by Sherman Yan on 12/6/22.
//

#ifndef FINALPROJECT_TEXTURES_H
#define FINALPROJECT_TEXTURES_H

#include "TexturesEnum.h"
#include <SFML/Graphics.hpp>
#include <map>


class Textures {

private:
    static std::map<TextureEnums, sf::Texture> map;
    static void load(TextureEnums texture);
    static std::string getPath(TextureEnums texture);
public:
    static sf::Texture& getTexture(TextureEnums texture);

};


#endif //FINALPROJECT_TEXTURES_H
