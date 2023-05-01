//
// Created by Brandon Hargitay on 4/30/23.
//

#include "PlayAudioMap.h"

void PlayAudioMap::playAudioMap(const std::map<float, std::vector<AudioNode>> &audioMap) {
    float previousTimeStamp = 0.0f;
    sf::Clock clock;

    for (const auto& timestampAndAudioNodes : audioMap) {
        float currentTimestamp = timestampAndAudioNodes.first;
        const std::vector<AudioNode>& audioNodes = timestampAndAudioNodes.second;

        float timeToWait = currentTimestamp - previousTimeStamp;

        // Wait until the time to play the next audio nodes
        while (clock.getElapsedTime().asSeconds() < timeToWait) {
            // Do nothing and wait for the time to elapse
        }

        // Reset the clock after the time has elapsed
        clock.restart();

        // Use a separate loop to play the sounds without modifying the const reference
        for (size_t i = 0; i < audioNodes.size(); i++) {
            AudioNode& audioNode = const_cast<AudioNode&>(audioNodes[i]);
            audioNode.play();
        }

        previousTimeStamp = currentTimestamp;
    }
}
