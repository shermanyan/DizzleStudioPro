//
// Created by Brandon Hargitay on 4/15/23.
//

#include <cmath>
#include "Analyser.h"

// Constructor for 'analyser' class; loads file, extracts audio details,
// and merges channels. Throws exception if file fails to open.
Analyser::Analyser(std::string filename, sf::Vector2u windowSize) : vb(sf::LineStrip) {
    this->windowSize = windowSize;
    textureX = 0.91 * windowSize.x;
    textureY = 0.15 * windowSize.y;
    lineThickness = 3.0f;

    if(!origbuffer.loadFromFile(filename))
        throw "Failed to open file!";

    //Load Details
    origchannelcount = origbuffer.getChannelCount();
    duration = origbuffer.getDuration();
    origsamplecount = origbuffer.getSampleCount();
    origsamplerate = origbuffer.getSampleRate();
    origsamples = origbuffer.getSamples();
    songDuration = duration.asSeconds();
    mergechannel();

}


// This function merges multi-channel audio into a mono channel by
// averaging corresponding samples, then loads the merged samples into 'monobuffer'
// and assigns it to 'sound'. If the audio is already mono, it proceeds without merging.
void Analyser::mergechannel() {
    if (origchannelcount==1) {
        for (int i=0; i<origsamplecount; i++)
            monosamples.push_back(origsamples[i]);
        monobuffer.loadFromSamples(&monosamples[0], origsamplecount, 1, origsamplerate);
        sound.setBuffer(monobuffer);
        return;
    }

    for (int i=0; i<origsamplecount; i+=2)
        monosamples.push_back((origsamples[i]+origsamples[i+1])/2);

    monobuffer.loadFromSamples(&monosamples[0], origsamplecount/2, 1, origsamplerate );
    sound.setBuffer(monobuffer);
}


// This function maps the mono audio samples to a new range (between 'low' and 'high')
// and stores the mapped values in 'mappedSample' vector.
void Analyser::mapBuffer() {
    int high = textureY / 2;
    int low = -textureY / 2;
    mappedSample.clear();

    int new_range = high - low;
    for (int i=0; i<origsamplecount/2; i++){
        mappedSample.push_back(low + ((monosamples[i]+32768)*new_range/65535));
    }
}

void Analyser::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    float firstRectCenterY = 0.0f;

    for (std::size_t i = 0; i < vertexCount - 1; i += 50 * 2) {
        if (i == 0) {
            float highestY = vertices[i].position.y;
            float lowestY = vertices[i].position.y;
            for (std::size_t j = i; j < i + 101 && j < vertexCount; ++j) {
                highestY = std::min(highestY, vertices[j].position.y);
                lowestY = std::max(lowestY, vertices[j].position.y);
            }
            firstRectCenterY = (highestY + lowestY) / 2.0f;
        }

        sf::RectangleShape columnRect = drawColumn(i, firstRectCenterY);
        target.draw(columnRect, states);
    }
}

void Analyser::createVisualizer() {
//Graph components
    vertexCount = mappedSample.size();
    vertexColorUpdated = new bool[vertexCount]{false};

    for (std::size_t i = 0; i < vertexCount;) {
        for (std::size_t j = 0; j < 100 && i < vertexCount; ++j, ++i) {
            float x = static_cast<float>(i) * textureX / vertexCount;
            float y = textureY / 2.0f + mappedSample[i];
            vertices.push_back(sf::Vertex(sf::Vector2f(x, y), sf::Color::White));
        }

        i += 90000; // Skip the next 100 vertices
    }

    // Update vertexCount to match the new size
    vertexCount = vertices.size();


    vb.create(vertexCount);


    rendergraph.create(textureX, textureY);

    graph.setTexture(rendergraph.getTexture());
    //graph.setPosition((windowSize.x-textureX)/2, (windowSize.y-textureY)*0.2);

}

void Analyser::updateVisualizer() {
    float now_seconds = sound.getPlayingOffset().asSeconds();

    int start = now_seconds * vertexCount / songDuration - 20;
    int end = now_seconds * vertexCount / songDuration + 20;

    // Find the starting and ending index for the vertices based on the loop in draw()
    int startIndex = std::max(0, static_cast<int>(std::floor(start / 100.0)) * 100);
    int endIndex = std::min(static_cast<int>(vertexCount), static_cast<int>(std::ceil(end / 100.0)) * 100);

    for (std::size_t i = startIndex; i < endIndex; i += 100) {
        if (i >= start && i <= end && !vertexColorUpdated[i]) {
            vertices[i].color = sf::Color::Green;
            vertexColorUpdated[i] = true;
        }
    }
    vb.update(vertices.data());
    rendergraph.clear();
    rendergraph.draw(vb);
}


void Analyser::activateVisulizer() {
    mapBuffer();
    createVisualizer();
    //sound.play();
}

void Analyser::setPosition(float x, float y) {
    visualizerPosition.x = x;
    visualizerPosition.y = y;
}

sf::RectangleShape Analyser::drawColumn(std::size_t i, float firstRectCenterY) const {
    float highestY = vertices[i].position.y;
    float lowestY = vertices[i].position.y;
    float currentX = vertices[i].position.x;

    for (std::size_t j = i; j < i + 101 && j < vertexCount; ++j) {
        highestY = std::min(highestY, vertices[j].position.y);
        lowestY = std::max(lowestY, vertices[j].position.y);
    }

    float centerY = (highestY + lowestY) / 2.0f;
    float yOffset = firstRectCenterY - centerY;
    float height = lowestY - highestY;
    sf::RectangleShape columnRect(sf::Vector2f(lineThickness, height));
    columnRect.setPosition(currentX + visualizerPosition.x, highestY + yOffset + visualizerPosition.y);
    columnRect.setFillColor(vertices[i].color);

    return columnRect;
}
