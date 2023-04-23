//
// Created by Brandon Hargitay on 4/22/23.
//

#ifndef DIZZLESTUDIOPRO_SONGINPUT_H
#define DIZZLESTUDIOPRO_SONGINPUT_H

#include "BasePanel.h"
#include "Squircle.h"
#include "TextInput.h"

class SongInput : public BasePanel {
private:
    TextInput songInput;
    sf::Text text;
    Squircle inner;
    Squircle outer;

    void setChildrenTransform(const sf::Transform &transform) override;

public:
    Squircle loadButton;

    std::string getSong();

    SongInput();

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    bool loadButonClicked(sf::RenderWindow &window);
};


#endif //DIZZLESTUDIOPRO_SONGINPUT_H
