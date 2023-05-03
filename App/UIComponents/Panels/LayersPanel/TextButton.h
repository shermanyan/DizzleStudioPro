//
// Created by Sherman Yan on 5/2/23.
//

#ifndef DIZZLESTUDIOPRO_TEXTBUTTON_H
#define DIZZLESTUDIOPRO_TEXTBUTTON_H

#include "Squircle.h"
#include "AppComponent.h"

class TextButton : public AppComponent {
private:
    sf::Text text;
    Squircle background;


public:
    TextButton();

    sf::FloatRect getGlobalBounds() const override;

    sf::FloatRect getLocalBounds() const override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    void setSize(float x, float y);

    void setText(const std::string &string);


};


#endif //DIZZLESTUDIOPRO_TEXTBUTTON_H
