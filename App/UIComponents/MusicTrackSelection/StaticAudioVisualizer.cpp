//
// Created by Brandon Hargitay on 4/19/23.
//

#include "StaticAudioVisualizer.h"

StaticAudioVisualizer::StaticAudioVisualizer(const std::string& filePath, unsigned int width, unsigned int height)
        : width(width), height(height) {
    sf::SoundBuffer buffer = Sounds::getSound(NARUTO);

//    if (!buffer.loadFromFile(filePath)) {
//        return;
//    }

    float barWidthScale = 0.2f; // Change this value to adjust the width of the bars
    float spacing = 2.0f;
    float barWidth = ((static_cast<float>(width) - spacing * (numBars - 1)) / numBars) * barWidthScale;
    visualizerBars.resize(numBars);

    const sf::Int16* samples = buffer.getSamples();
    std::size_t sampleCount = buffer.getSampleCount();

    for (unsigned int i = 0; i < numBars; ++i) {
        float average = 0.0f;
        unsigned int samplesPerBar = sampleCount / numBars;
        for (unsigned int j = i * samplesPerBar; j < (i + 1) * samplesPerBar; ++j) {
            average += std::abs(samples[j]);
        }
        average /= samplesPerBar;

        float normalizedAverage = average / 32768.0f;
        float barHeight = normalizedAverage * height;

        float halfBarHeight = barHeight / 2;
        visualizerBars[i].setSize(sf::Vector2f(barWidth, barHeight));
        visualizerBars[i].setPosition(i * (barWidth + spacing), height / 2.0f - halfBarHeight);
    }
}



void StaticAudioVisualizer::setScale(float scaleX, float scaleY) {
    transform.scale(scaleX, scaleY);
}

void StaticAudioVisualizer::setPosition(float posX, float posY) {
    float spacing = 15.0f;
    for (unsigned int i = 0; i < numBars; ++i) {
        float barX = posX + i * (visualizerBars[i].getSize().x + spacing);
        float barY = posY + (height / 2.0f - visualizerBars[i].getSize().y / 2);
        visualizerBars[i].setPosition(barX, barY);
    }
}

void StaticAudioVisualizer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= transform;
    for (const auto& bar : visualizerBars) {
        target.draw(bar, states);
    }
}

void StaticAudioVisualizer::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

}

void StaticAudioVisualizer::update(const sf::RenderWindow &window) {

}
