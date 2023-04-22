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
        Squircle loadButton;
        sf::Text text;
public:

    SongInput();

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void init();

    void setParentTransform(const sf::Transform &transform) override;

};


#endif //DIZZLESTUDIOPRO_SONGINPUT_H
