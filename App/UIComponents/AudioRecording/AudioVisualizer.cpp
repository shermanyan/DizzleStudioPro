//
// Created by Brandon Hargitay on 4/19/23.
//

#include <iostream>
#include "AudioVisualizer.h"
#include "Position.h"

AudioVisualizer::AudioVisualizer(unsigned int width, unsigned int height)
        : width(width), height(height) {
    float barWidthScale = 0.5f; // Change this value to adjust the width of the bars
    float spacing = -5.0f;
    float barWidth = ((static_cast<float>(width) - spacing * (numBars - 1)) / numBars) * barWidthScale;
    visualizerBars.resize(numBars);
    for (unsigned int i = 0; i < numBars; ++i) {
        visualizerBars[i].setSize(sf::Vector2f(barWidth, 0));
        visualizerBars[i].setPosition(i * (barWidth + spacing), height);
    }

}


bool AudioVisualizer::startRecording() {
    if (sf::SoundRecorder::isAvailable()) {
        setProcessingInterval(sf::milliseconds(100));
        return sf::SoundRecorder::start();
    } else {
        return false;
    }
}

void AudioVisualizer::stopRecording() {
    sf::SoundRecorder::stop();

    std::string filename = "recorded_sound.wav";
    sf::SoundBuffer soundBuffer;
    soundBuffer.loadFromSamples(&sampleBuffer[0], sampleBuffer.size(), 1, getSampleRate());
    if (soundBuffer.saveToFile(filename)) {
        std::cout << "Recorded sound saved to " << filename << std::endl;
    } else {
        std::cerr << "Failed to save recorded sound to " << filename << std::endl;
    }
}

bool AudioVisualizer::onProcessSamples(const sf::Int16* samples, std::size_t sampleCount) {
    sampleBuffer.insert(sampleBuffer.end(), samples, samples + sampleCount);

    for (unsigned int i = 0; i < numBars; ++i) {
        float average = 0.0f;
        unsigned int samplesPerBar = sampleCount / numBars;
        for (unsigned int j = i * samplesPerBar; j < (i + 1) * samplesPerBar; ++j) {
            average += std::abs(samples[j]);
        }
        average /= samplesPerBar;

        // Apply the sensitivity factor to the average value
        average *= 4;

        // Normalize the average to a value between 0 and 1
        float normalizedAverage = average / 32768.0f;
        float barHeight = normalizedAverage * height;

        // Add a minimum height for the bars
        float minHeight = 0.005f * height;
        barHeight = std::max(minHeight, barHeight);

        // Enforce the maxBarHeight limit
        barHeight = std::min(250.f, barHeight);

        // Update the rectangle
        float halfBarHeight = barHeight / 2;
        visualizerBars[i].setSize(sf::Vector2f(visualizerBars[i].getSize().x, barHeight));
//        visualizerBars[i].setPosition(visualizerBars[i].getPosition().x, height / 2.0f - halfBarHeight);
    }
    reposition();

    return true;
}


void AudioVisualizer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (const auto& bar : visualizerBars) {
        target.draw(bar, states);
    }
}


//void AudioVisualizer::setPosition(sf::Vector2f pos) {
//    float spacing = 10.0f; // Change this value to adjust the spacing between bars
//    for (unsigned int i = 0; i < numBars; ++i) {
//        float barX = pos.x + i * (visualizerBars[i].getSize().x + spacing);
//        float barY = pos.y + (height / 2.0f - visualizerBars[i].getSize().y / 2);
//        visualizerBars[i].setPosition(barX, barY);
//    }
//}

void AudioVisualizer::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

}

void AudioVisualizer::update(const sf::RenderWindow &window) {

}

sf::FloatRect AudioVisualizer::getGlobalBounds() const {
    sf::FloatRect bounds;
    bounds.width = width;
    bounds.height = height;

    return getTransform().transformRect(bounds);
}

void AudioVisualizer::reposition() {
    float spacing = 10.0f; // Change this value to adjust the spacing between bars
//    for (unsigned int i = 0; i < numBars; ++i) {
//        float barX = pos.x + i * (visualizerBars[i].getSize().x + spacing);
//        float barY = pos.y + (height / 2.0f - visualizerBars[i].getSize().y / 2);
//        visualizerBars[i].setPosition(barX, barY);
//    }

    visualizerBars.front().setPosition(0,height /2 - visualizerBars.front().getGlobalBounds().height/2);
//    float spacing = 15.0f;
    for (int i = 1; i < visualizerBars.size(); ++i) {
        Position::center(visualizerBars[i], visualizerBars[i-1]);
        Position::right(visualizerBars[i], visualizerBars[i - 1], spacing);
    }
}





<<<<<<< HEAD


=======
>>>>>>> Sherman
