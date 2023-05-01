//
// Created by Sherman Yan on 4/14/23.
//

#include "Layer.h"

Layer::Layer() {
    setTrack(EMPTY);
    setState(SELECTED,false);
}

void Layer::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    if(event.type == sf::Event::KeyPressed && MouseEvents::isHover(getCombinedTransform().transformRect(label.getGlobalBounds()),window)) {
        sf::Keyboard::Key key = event.key.code;
        switch (key) {
            case sf::Keyboard::K: {
                setTrack(KEYBOARD);
                break;
            }
            case sf::Keyboard::V: {
                setTrack(VOCAL);
                break;
            }
            case sf::Keyboard::A: {
                setTrack(AUDIO);
                break;
            }
        }
    }

    if (!checkStates(SELECTED)&&event.type == sf::Event::MouseButtonPressed &&
            MouseEvents::isClick(getCombinedTransform().transformRect(track->getGlobalBounds()), window)) {
        StudioStatics::panel->setActivePanel(label.getTrackType());
        setState(SELECTED, true);
        track->setState(SELECTED, true);
    }
    if(!checkStates(SELECTED))
        track->setState(SELECTED, false);


    label.eventHandler(window, event);
    track->eventHandler(window, event);


    if(checkStates(SELECTED)){
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                // Space bar is pressed, perform your desired action here
                sf::SoundBuffer combinedBuffer = concatenateSounds(track->getAudioTrack(), 44100);
                test.setBuffer(combinedBuffer);
                test.play();
                std::cout << "PRESSED";
                sf::sleep(sf::seconds(combinedBuffer.getDuration().asSeconds()));

//                playAudioMap(track->getAudioTrack());
            }
        }
    }

//        if (instrumentPanel->getActivePanel() == label.getTrackType() && label.getTrackType() != EMPTY) {
//            bool drawNew = true;
//            if(label.getTrackType() == KEYBOARD){
//                AudioNode key = instrumentPanel->getPanel()->getKeyPressed(window);
//                AudioNode* lastKey = &track.getLastNode().getNode();
//                if (key.keyEnum != NULL_KEY && key.keyEnum == lastKey->keyEnum) {
//                    lastKey->setStopTimeStamp(seekBar->getElapsedTime());
//                    drawNew = false;
//                }
//            }
//            if(drawNew) {
//                AudioNode key = instrumentPanel->getPanel()->getKeyPressed(window);
//                if (key.keyEnum != NULL_KEY) {
//                    track.emplace_back(seekBar->getElapsedTime(), key);
//                }
//            }
//        }


}

void Layer::update(const sf::RenderWindow &window) {
    if(checkStates(SELECTED)) {
        label.update(window);
        track->update(window);
    }

}

void Layer::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    states.transform *= getTransform();
    target.draw(label,states);
    target.draw(*track,states);

}

void Layer::setChildrenTransform(const sf::Transform &transform) {
    label.setParentTransform(transform);
    track->setParentTransform(transform);
}

void Layer::setTrackColor(const sf::Color &color) {
    label.setTrackColor(color);
}

void Layer::setTrack(InstrumentsEnum type) {
    label.setTrack(type);

    switch (type) {
        case EMPTY: {
            track = std::make_unique<Track>();
            break;
        }
        case KEYBOARD:{
            track = std::make_unique<KeyboardTrack>();
            break;
        }
        case DRUMPAD: {
            track = std::make_unique<DrumPadTrack>();
            break;
        }
        case AUDIO: {
            track = std::make_unique<AudioTrack>();
            break;
        }
        case VOCAL: {
            track = std::make_unique<VocalTrack>();
        }


    }

    track->setTrackColor(label.getTrackColor());
    track->setParentTransform(getTransform());
    Position::right(*track,label,10);
}

sf::FloatRect Layer::getGlobalBounds() const {
    sf::FloatRect bounds = label.getGlobalBounds();
    bounds.width += 10 + track->getGlobalBounds().width;

    return getTransform().transformRect(bounds);
}

sf::FloatRect Layer::getLocalBounds() const {
    return label.getLocalBounds();
}

InstrumentsEnum Layer::getTrackType() const {
    return label.getTrackType();
}

void Layer::playAudioMap(const std::map<float, std::vector<AudioNode>>& audioMap) {
    float previousTimeStamp = 0.0f;

    for (const auto& timestampAndAudioNodes : audioMap) {
        float currentTimestamp = timestampAndAudioNodes.first;
        const std::vector<AudioNode>& audioNodes = timestampAndAudioNodes.second;

        sf::Time timeToSleep = sf::seconds(currentTimestamp - previousTimeStamp);
        sf::sleep(timeToSleep);

        // Use a separate loop to play the sounds without modifying the const reference
        for (size_t i = 0; i < audioNodes.size(); i++) {
            AudioNode& audioNode = const_cast<AudioNode&>(audioNodes[i]);
            audioNode.play();
        }

        previousTimeStamp = currentTimestamp;
    }
}



sf::SoundBuffer Layer::concatenateSounds(const std::map<float, std::vector<AudioNode>>& audioMap, unsigned int targetSampleRate) {
    std::vector<sf::Int16> samples;

// calculate the total number of samples needed
    std::size_t totalSampleCount = 0;
    for (const auto& timestampAndAudioNodes : audioMap) {
        for (const AudioNode& audioNode : timestampAndAudioNodes.second) {
            sf::SoundBuffer monoBuffer = convertToMono(audioNode.buffer);
            sf::SoundBuffer resampledBuffer = resampleSoundBuffer(monoBuffer, 44100);
            std::size_t durationSampleCount = static_cast<std::size_t>(audioNode.duration * resampledBuffer.getSampleRate());
            totalSampleCount += std::min(durationSampleCount, static_cast<std::size_t>(resampledBuffer.getSampleCount()));
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
            sf::SoundBuffer monoBuffer = convertToMono(audioNode.buffer);
            sf::SoundBuffer resampledBuffer = resampleSoundBuffer(monoBuffer, 44100);

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

sf::SoundBuffer Layer::convertToMono(const sf::SoundBuffer &buffer) {
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
    return monoBuffer;}

sf::SoundBuffer Layer::resampleSoundBuffer(const sf::SoundBuffer &buffer, unsigned int targetSampleRate) {
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
    return resampledBuffer;}




