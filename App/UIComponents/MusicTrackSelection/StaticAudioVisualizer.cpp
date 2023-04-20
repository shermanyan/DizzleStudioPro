//
// Created by Brandon Hargitay on 4/19/23.
//

#include <iostream>
#include "StaticAudioVisualizer.h"

StaticAudioVisualizer::StaticAudioVisualizer(const std::string& filePath, const sf::Vector2u& size)
        : width(size.x), height(size.y) {

    loadVisualizer(filePath);
}



void StaticAudioVisualizer::setPosition(const sf::Vector2f & pos) {
    float spacing = 15.0f;
    for (unsigned int i = 0; i < visualizerBars.size(); ++i) {
        float barX = pos.x + i * (visualizerBars[i].getSize().x + spacing);
        float barY = pos.y - visualizerBars[i].getSize().y / 2;
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

    if (sound.getStatus() != sf::Sound::Playing) {
        sound.play();
        isPlaying = true;
    } else {
        sound.stop();
        isPlaying = false;
        for (auto& bar : visualizerBars) {
            bar.setFillColor(sf::Color::White);
        }
    }

    if(event.key.code == sf::Keyboard::P) {
        sound.stop();
        isPlaying = false;
        for (auto& bar : visualizerBars) {
            bar.setFillColor(sf::Color::White);
        }
    }

}

void StaticAudioVisualizer::update(const sf::RenderWindow &window) {
    if (isPlaying) {
        updateColors();
    }
}

void StaticAudioVisualizer::updateColors() {

    float currentTime = sound.getPlayingOffset().asSeconds();
    float duration = sound.getBuffer()->getDuration().asSeconds();

    float progress = currentTime / duration;

    for (unsigned int i = 0; i < visualizerBars.size(); ++i) {

        float barProgress = static_cast<float>(i) / visualizerBars.size();
        if (barProgress <= progress) {
            visualizerBars[i].setFillColor(sf::Color::Green);
        } else {
            visualizerBars[i].setFillColor(sf::Color::White);
        }
    }
}

void StaticAudioVisualizer::loadVisualizer(const std::string &filePath) {
//    buffer = Sounds::getSound(NARUTO);

    if (!buffer.loadFromFile("App/Resources/Sounds/TestSounds/" + filePath)) {
        std::cout << "Fail";
    }
    sound.setBuffer(buffer);

    float spacing = 15.0f;
    float barWidth = 5.0f;
    unsigned int numBars = static_cast<unsigned int>((width - spacing) / (barWidth + spacing));

    visualizerBars.resize(numBars);

    const sf::Int16 *samples = buffer.getSamples();
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
        float clampedBarHeight = std::min(barHeight, 320.f);

        visualizerBars[i].setSize(sf::Vector2f(barWidth, clampedBarHeight));
    }
    setPosition({0,0});
}

sf::SoundBuffer StaticAudioVisualizer::getSong() {
    return buffer;
}


