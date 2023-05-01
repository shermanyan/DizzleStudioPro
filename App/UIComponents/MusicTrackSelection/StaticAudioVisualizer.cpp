//
// Created by Brandon Hargitay on 4/19/23.
//

#include "StaticAudioVisualizer.h"

StaticAudioVisualizer::StaticAudioVisualizer(const std::string& filePath, const sf::Vector2u& size)
        : width(size.x), height(size.y) {
//    loadVisualizer(filePath);

}

void StaticAudioVisualizer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (const auto& bar : visualizerBars) {
        target.draw(bar, states);
    }
}

void StaticAudioVisualizer::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

    if (sound.getStatus() != sf::Sound::Playing) {
        AudioNode::play();
        isPlaying = true;
    } else {
       AudioNode::stop();
        isPlaying = false;
        for (auto& bar : visualizerBars) {
            bar.setFillColor({121,121,121});

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
            visualizerBars[i].setFillColor({14,122,40});
        } else {
            visualizerBars[i].setFillColor({121,121,121});
        }
    }
}

void StaticAudioVisualizer::loadVisualizer(const std::string &filePath) {
    // buffer = Sounds::getSound(NARUTO);
    visualizerBars.clear();
    if (!buffer.loadFromFile("App/Resources/Sounds/TestSounds/" + filePath)) {
        std::cout << "Fail";
    }
    AudioNode::setBuffer(buffer);

    float spacing = 15.0f;
    float barWidth = 12.0f;

    unsigned int numBars = static_cast<unsigned int>((width - spacing) / (barWidth + spacing));

    visualizerBars.reserve(numBars); // Reserve space for visualizer bars

    const sf::Int16 *samples = buffer.getSamples();
    std::size_t sampleCount = buffer.getSampleCount();
    unsigned int samplesPerBar = sampleCount / numBars;

    for (unsigned int i = 0; i < numBars; ++i) {
        float average = 0.0f;
        unsigned int sampleStart = i * samplesPerBar;
        unsigned int sampleEnd = sampleStart + samplesPerBar;

        for (unsigned int j = sampleStart; j < sampleEnd; ++j) {
            average += std::abs(samples[j]);
        }
        average /= samplesPerBar;

        float normalizedAverage = average / 32768.0f;
        float barHeight = normalizedAverage * height;
        float clampedBarHeight = std::min(barHeight, 320.f);

        visualizerBars.emplace_back(Squircle(sf::Vector2f(barWidth, clampedBarHeight), 5)); // Construct in place
//        visualizerBars[i].setRadius(5);
        visualizerBars[i].setFillColor({121,121,121});
    }

    this->duration = sound.getBuffer()->getDuration().asSeconds();
    reposition();
}



void StaticAudioVisualizer::reposition() {

    visualizerBars.front().setPosition(0,height /2 - visualizerBars.front().getGlobalBounds().height/2);
    for (int i = 1; i < visualizerBars.size(); ++i) {
        Position::center(visualizerBars[i], visualizerBars[i-1]);
        Position::right(visualizerBars[i], visualizerBars[i - 1], spacing);
    }

}

sf::FloatRect StaticAudioVisualizer::getGlobalBounds() const {
    sf::FloatRect bounds;
    bounds.width = width;
    bounds.height = height;

    return getTransform().transformRect(bounds);
}