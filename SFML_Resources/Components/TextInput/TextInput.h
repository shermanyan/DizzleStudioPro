//
// Created by Sherman Yan on 3/20/23.
//

#ifndef TEXTINPUT_TEXTINPUT_H
#define TEXTINPUT_TEXTINPUT_H

#include "TextBox.h"
#include "AppComponent.h"
#include "TextboxLabel.h"

class TextInput: public AppComponent{
private:
    TextBox textBox;
    TextboxLabel label;
    bool isOperator(char c);

    void colorWord(MultiText *&text, const std::string &target, const sf::Color &color);

public:
    TextInput();
    TextInput(const std::string& label);

    void setLabelString(const std::string& label);
    void setLabelCharacterSize(unsigned int size);
    void setLabelFont(sf::Font& font);
    void setLabelFillColor(const sf::Color& color);
    void setTextBoxFont(sf::Font& font);
    void setCharacterFillColor(const sf::Color& color);
    void setOutlineThickness(float size);
    void setTextBoxSize(const sf::Vector2f& size);
    void setTextBoxFillColor(const sf::Color& color);
    void setTextBoxOutlineColor(const sf::Color& color);

    sf::FloatRect getGlobalBounds() const;
    sf::FloatRect getLocalBounds() const;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void update(const sf::RenderWindow &window) override;

    void setPosition(const sf::Vector2f& pos);
    void setPosition(float x, float y);

};


#endif //TEXTINPUT_TEXTINPUT_H
