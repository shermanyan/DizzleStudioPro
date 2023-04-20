//
// Created by Sherman Yan on 4/19/23.
//

#ifndef DIZZLESTUDIOPRO_EMPTYPANEL_H
#define DIZZLESTUDIOPRO_EMPTYPANEL_H


#include "BasePanel.h"
#include "Keyboard.h"
#include "Fonts.h"

class EmptyPanel: public BasePanel{
private:
    sf::Text text;

public:
    EmptyPanel();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};


#endif //DIZZLESTUDIOPRO_EMPTYPANEL_H
