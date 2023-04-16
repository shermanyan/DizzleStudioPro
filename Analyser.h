//
// Created by Brandon Hargitay on 4/15/23.
//

#ifndef DIZZLESTUDIOPRO_ANALYSER_H
#define DIZZLESTUDIOPRO_ANALYSER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Analyser : public sf::Drawable{
public:
    //Functions
    void mergechannel();
    void createVisualizer();
    //Original
    sf::SoundBuffer origbuffer;
    const sf::Int16* origsamples;
    unsigned int origchannelcount;
    unsigned int origsamplerate;
    sf::Uint64 origsamplecount;

    //Mono
    sf::SoundBuffer monobuffer;
    std::vector<sf::Int16> monosamples;

    //Window Size
    sf::Vector2u windowSize;
    int textureX;
    int textureY;

    sf::RenderTexture rendergraph;
    sf::Sprite graph;

    void updateVisualizer();
    std::size_t vertexCount;
    std::vector<sf::Vertex> vertices;
    bool* vertexColorUpdated;
    sf::VertexBuffer vb;

public:
    sf::Sound sound;
    sf::Time duration;
    Analyser(std::string filename, sf::Vector2u windowSize);
    void mapBuffer();
    std::vector<sf::Int16> mappedSample;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    int songDuration;
    void activateVisulizer();
    void setPosition(float x, float y);
};


#endif //DIZZLESTUDIOPRO_ANALYSER_H
