//
// Created by Brandon Hargitay on 4/23/23.
//

#ifndef DIZZLESTUDIOPRO_LAYERDROPDOWNMENU_H
#define DIZZLESTUDIOPRO_LAYERDROPDOWNMENU_H

#include "AppComponent.h"
#include "SpriteImage.h"
#include "Textures.h"

class LayerDropDownMenu : public AppComponent{
private:
    SpriteImage dropDownMenu;

public:
    LayerDropDownMenu();

    void setSize(sf::Vector2f size);

    sf::FloatRect getGlobalBounds() const override;

    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;


    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //DIZZLESTUDIOPRO_LAYERDROPDOWNMENU_H
