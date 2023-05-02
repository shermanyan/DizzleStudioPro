//
// Created by Brandon Hargitay on 4/30/23.
//

#include "GetBuffer.h"


sf::SoundBuffer GetBuffer::getCombinedSoundBuffer(const std::map<float, std::vector<AudioNode>> &audioMap,
                                                unsigned int targetSampleRate) {
    std::vector<sf::Int16> samples;

// calculate the total number of samples needed
    std::size_t totalSampleCount = 0;
    for (const auto& timestampAndAudioNodes : audioMap) {
        for (const AudioNode& audioNode : timestampAndAudioNodes.second) {
            sf::SoundBuffer resampledBuffer = resampleSoundBuffer(convertToMono(audioNode.buffer), 44100);
            std::size_t durationSampleCount = static_cast<std::size_t>(audioNode.duration * resampledBuffer.getSampleRate());
            totalSampleCount += std::max(durationSampleCount, static_cast<std::size_t>(resampledBuffer.getSampleCount()));
        }
    }

// add enough 0s to the output buffer to accommodate all the samples
    samples.resize(totalSampleCount, 0);

// add the samples to the output buffer at the correct position
    std::size_t outputPosition = 0;
    for (const auto& timestampAndAudioNodes : audioMap) {
        const float timestamp = timestampAndAudioNodes.first;
        const std::vector<AudioNode>& audioNodes = timestampAndAudioNodes.second;

        for (const AudioNode& audioNode : audioNodes) {
            sf::SoundBuffer resampledBuffer = resampleSoundBuffer(convertToMono(audioNode.buffer), 44100);

            const sf::Int16* bufferSamples = resampledBuffer.getSamples();
            std::size_t bufferSampleCount = resampledBuffer.getSampleCount();

            // Calculate the number of samples to copy based on the duration
            std::size_t samplesToCopy = static_cast<std::size_t>(audioNode.duration * resampledBuffer.getSampleRate());
            samplesToCopy = std::min(samplesToCopy, bufferSampleCount);

            // Calculate the position in the output buffer to add the samples
            outputPosition = std::round(timestamp * 44100);

            // Ensure there is enough space in the output buffer to add the samples
            if (outputPosition + samplesToCopy > samples.size()) {
                samples.resize(outputPosition + samplesToCopy, 0);
            }

            // Add the samples to the output buffer at the correct position
            std::copy(bufferSamples, bufferSamples + samplesToCopy, samples.begin() + outputPosition);

            // Update the output position
            outputPosition += samplesToCopy;
        }
    }

    sf::SoundBuffer result;
    if (!result.loadFromSamples(samples.data(), samples.size(), 1, targetSampleRate)) {
        std::cerr << "Failed to load samples into resulting sound buffer" << std::endl;
    }

    return result;
}

sf::SoundBuffer GetBuffer::convertToMono(const sf::SoundBuffer &buffer) {
    if (buffer.getChannelCount() == 1) {
        return buffer;
    }

    std::size_t sampleCount = buffer.getSampleCount();
    const sf::Int16* samples = buffer.getSamples();

    std::size_t monoSampleCount = sampleCount / 2;
    std::vector<sf::Int16> monoSamples(monoSampleCount);

    for (std::size_t i = 0; i < monoSampleCount; ++i) {
        monoSamples[i] = static_cast<sf::Int16>((samples[2 * i] + samples[2 * i + 1]) / 2);
    }

    sf::SoundBuffer monoBuffer;
    monoBuffer.loadFromSamples(monoSamples.data(), monoSampleCount, 1, buffer.getSampleRate());
    return monoBuffer;
}

sf::SoundBuffer GetBuffer::resampleSoundBuffer(const sf::SoundBuffer &buffer, unsigned int targetSampleRate) {
    unsigned int originalSampleRate = buffer.getSampleRate();
    if (originalSampleRate == targetSampleRate) {
        return buffer;
    }

    std::size_t originalSampleCount = buffer.getSampleCount();
    const sf::Int16* originalSamples = buffer.getSamples();

    std::size_t resampledSampleCount = std::ceil(static_cast<double>(originalSampleCount) * targetSampleRate / originalSampleRate);
    std::vector<sf::Int16> resampledSamples(resampledSampleCount);

    for (std::size_t i = 0; i < resampledSampleCount; ++i) {
        double originalSamplePosition = static_cast<double>(i) * originalSampleRate / targetSampleRate;
        std::size_t originalSampleIndex = static_cast<std::size_t>(std::floor(originalSamplePosition));
        double fraction = originalSamplePosition - originalSampleIndex;

        if (originalSampleIndex + 1 < originalSampleCount) {
            resampledSamples[i] = static_cast<sf::Int16>(originalSamples[originalSampleIndex] * (1.0 - fraction) + originalSamples[originalSampleIndex + 1] * fraction);
        } else {
            resampledSamples[i] = originalSamples[originalSampleIndex];
        }
    }

    sf::SoundBuffer resampledBuffer;
    resampledBuffer.loadFromSamples(resampledSamples.data(), resampledSampleCount, 1, targetSampleRate);
    return resampledBuffer;
}

