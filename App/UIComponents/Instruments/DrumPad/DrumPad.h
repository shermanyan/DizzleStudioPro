//
// Created by Sherman Yan on 4/14/23.
//

#ifndef DIZZLESTUDIOPRO_DRUMPAD_H
#define DIZZLESTUDIOPRO_DRUMPAD_H
#include "Position.h"
#include "Pads.h"

class DrumPad : public AppComponent{
public:
    DrumPad();
    DrumPad(const sf::Vector2f &size, int numOfPads);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;
    void update(const sf::RenderWindow &window) override;
    float getKeySpacing() const;

private:
    std::vector<Pads> pads;
    int numOfPads;
    sf::Vector2f size;
    float spacing;

    void setupPads();
    void positionPads();
    sf::Vector2f calculatePadSize() const;

    void setChildrenTransform(const sf::Transform& transform) override;


};


#endif //DIZZLESTUDIOPRO_DRUMPAD_H
