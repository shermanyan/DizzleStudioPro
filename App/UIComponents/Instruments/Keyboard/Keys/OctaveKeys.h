//
// Created by Sherman Yan on 4/14/23.
//

#ifndef DIZZLESTUDIOPRO_OCTAVEKEYS_H
#define DIZZLESTUDIOPRO_OCTAVEKEYS_H

#include "Key.h"
#include "UIComponents/Instruments/SoundKeys.h"
#include <map>

class OctaveKeys: public AppComponent {
private:

    sf::Vector2f size;
    sf::Vector2f blackKeySizeRatio = {0.8f, 0.6f};

    sf::Vector2<sf::Color> keyColors;
    float spacing = 10;

    std::map<SoundKeys,Key> whiteKeys;
    std::map<SoundKeys,Key> blackKeys;

    //refresh key positions
    void refresh();

    //setup keys position and color
    void setupKeys();

    //setup white keys color and positions;
    void setUpWhiteKeys();

    //setup black keys color and positions;
    void setupBlackKeys();

    void setWhiteKeysSize();
    void setBlackKeysSize();

    void positionKeys();

    void setChildrenTransform(const sf::Transform& transform) override;

public:
    //Default Constructor
    //Size: {760,347}
    OctaveKeys();
    //Constructor
    //Input: size, key colors
    OctaveKeys(const sf::Vector2f& size, const sf::Vector2<sf::Color>& keyColors);
    //Constructor
    //Input: key colors
    OctaveKeys(const sf::Vector2<sf::Color>& keyColors);

    //Set octave size
    void setSize(const sf::Vector2f& size);

    //Set key colors
    void setFillColors(const sf::Vector2<sf::Color>& keyColors);
    //Set fill color for black key
    void setBlackKeyColor(const sf::Color& color);
    //Set fill color for white key
    void setWhiteKeyColor(const sf::Color& color);

    //Set spacing between keys
    void setKeySpacing(float spacing);

    float getKeySpacing() const;

    SoundKeys getKeyPress(const sf::RenderWindow& window) const;

    sf::FloatRect getGlobalBounds() const override;
    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow &window, const sf::Event &event) override;

    void update(const sf::RenderWindow &window) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};


#endif //DIZZLESTUDIOPRO_OCTAVEKEYS_H
