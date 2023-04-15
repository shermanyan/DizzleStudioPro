//
// Created by Sherman Yan on 12/6/22.
//

#ifndef FONTS_H
#define FONTS_H

#include "Enums/FontsEnum.h"
#include <SFML/Graphics.hpp>
#include <map>

class Fonts {

private:
    static std::map<FontsEnum, sf::Font> map;
    static void load(FontsEnum font);
    static std::string getPath(FontsEnum font);
public:
    static sf::Font& getFont(FontsEnum font);

};

#endif //FONTS_H
