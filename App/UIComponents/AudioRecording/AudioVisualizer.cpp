//
// Created by Brandon Hargitay on 4/19/23.
//

#include <iostream>
#include "AudioVisualizer.h"
#include "Position.h"

AudioVisualizer::AudioVisualizer(unsigned int width, unsigned int height)
        : width(width), height(height) {
    float spacing = 20.0f;
    float barWidth = 5;
//    float barWidth = ((static_cast<float>(width) - spacing * (numBars - 1)) / numBars) * barWidthScale;
    visualizerBars.resize(numBars);
    for (unsigned int i = 0; i < numBars; ++i) {
        visualizerBars[i].setSize(sf::Vector2f(barWidth, 0));
        visualizerBars[i].setPosition(i * (barWidth + spacing), height);
    }

}


bool AudioVisualizer::startRecording() {
    if (sf::SoundRecorder::isAvailable()) {
        // Clear sampleBuffer and recordedSoundBuffer
        sampleBuffer.clear();
        recordedSoundBuffer = sf::SoundBuffer();

        setProcessingInterval(sf::milliseconds(100));
        return sf::SoundRecorder::start();
    } else {
        return false;
    }
}

void AudioVisualizer::stopRecording() {
    sf::SoundRecorder::stop();

    recordedSoundBuffer.loadFromSamples(sampleBuffer.data(), sampleBuffer.size(), 1, getSampleRate());

}

bool AudioVisualizer::onProcessSamples(const sf::Int16* samples, std::size_t sampleCount) {
    sampleBuffer.insert(sampleBuffer.end(), samples, samples + sampleCount);

    // Calculate the average amplitude for the new rightmost bar
    float average = 0.0f;
    for (unsigned int j = 0; j < sampleCount; ++j) {
        average += std::abs(samples[j]);
    }
    average /= sampleCount;

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

    // Shift the bar heights to the left
    for (unsigned int i = 0; i < numBars - 1; ++i) {
        float leftBarHeight = visualizerBars[i + 1].getSize().y;
        visualizerBars[i].setSize(sf::Vector2f(visualizerBars[i].getSize().x, leftBarHeight));
    }

    // Update the rightmost rectangle
    visualizerBars[numBars - 1].setSize(sf::Vector2f(visualizerBars[numBars - 1].getSize().x, barHeight));

    reposition();

    return true;
}


void AudioVisualizer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (const auto& bar : visualizerBars) {
        target.draw(bar, states);
    }
}




sf::FloatRect AudioVisualizer::getGlobalBounds() const {
    sf::FloatRect bounds;
    bounds.width = width;
    bounds.height = height;

    return getTransform().transformRect(bounds);
}

void AudioVisualizer::reposition() {
    float spacing = 10.0f; // Change this value to adjust the spacing between bars


    visualizerBars.front().setPosition(0,height /2 - visualizerBars.front().getGlobalBounds().height/2);
    for (int i = 1; i < visualizerBars.size(); ++i) {
        Position::center(visualizerBars[i], visualizerBars[i-1]);
        Position::right(visualizerBars[i], visualizerBars[i - 1], spacing);
    }
}

void AudioVisualizer::saveRecordedSoundToFile(const std::string &filename) {
    sf::SoundBuffer soundBuffer;
    soundBuffer.loadFromSamples(sampleBuffer.data(), sampleBuffer.size(), 1, getSampleRate());

    if (soundBuffer.saveToFile(filename)) {
        std::cout << "Recorded sound saved to " << filename << std::endl;
    } else {
        std::cerr << "Failed to save recorded sound to " << filename << std::endl;
    }
}

void AudioVisualizer::playRecordedSound() {
    recordedSound.setBuffer(recordedSoundBuffer);
    recordedSound.play();
}

void AudioVisualizer::resetVisualizerBars() {
    float spacing = 20.0f;
    float barWidth = 5;

    for (unsigned int i = 0; i < numBars; ++i) {
        visualizerBars[i].setSize(sf::Vector2f(barWidth, 0));
        visualizerBars[i].setPosition(i * (barWidth + spacing), height);
    }
}

void AudioVisualizer::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

}

void AudioVisualizer::update(const sf::RenderWindow &window) {

}