//
// Created by Sherman Yan on 3/5/23.
//

#ifndef MULTITEXT_H
#define MULTITEXT_H
#include <list>
#include "Letter.h"

class MultiText :public sf::Drawable, public sf::Transformable {

private:
    std::list<Letter> text;
    Letter letter;
public:
    MultiText();
    MultiText(const std::string& text);

    void addCharacter(char c);
    void pop_back();
    void pop_front();
    void push_front(Letter letter);

    Letter* front();
    Letter* back();

    void clear();

    int length();

    void setString(const std::string &text);
    std::string getString();

    void setCharacterSize(unsigned int size);
    unsigned int getCharacterSize();

    void setFillColor(const sf::Color& color);
    void setFillColor(const sf::Color& color, int index, int length = 1);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void setFont(const sf::Font &font);

    sf::FloatRect getGlobalBounds()const;
    sf::FloatRect getLocalBounds()const;

    void updatePosition();
};


#endif //TYPINGINSFML_MULTITEXT_H
