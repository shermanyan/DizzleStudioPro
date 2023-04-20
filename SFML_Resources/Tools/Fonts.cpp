//
// Created by Sherman Yan on 12/6/22.
//

#include "Fonts.h"

std::map<FontsEnum, sf::Font> Fonts::map;

void Fonts::load(FontsEnum font) {

    if (map.count(font) == 0 && !map[font].loadFromFile(getPath(font)))
        exit(20);

}

std::string Fonts::getPath(FontsEnum font) {
    switch (font) {
        case OPEN_SANS:
            return "SFML_Resources/fonts/OpenSans-Bold.ttf";
        case NUNITO_BOLD:
            return "SFML_Resources/Fonts/Nunito-ExtraBold.ttf";
        case LAST_FONT:
            break;
    }
}

sf::Font &Fonts::getFont(FontsEnum font) {
    if (map.count(font) == 0)
        load(font);
    return map.at(font);
}
