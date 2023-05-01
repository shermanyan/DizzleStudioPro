//
// Created by Sherman Yan on 4/23/23.
//

#include "KeyboardTrack.h"

KeyboardTrack::KeyboardTrack(): Track{} {

//    setFillColor(sf::Color::Red);

    for (int i = 0; i < KeyboardPanel::octaveCount; ++i) {
        nodes.emplace_back();
        for (int j = C; j <= As; ++j) {
            nodes.back()[SoundKeys(j)] = nullptr;
        }
    }
}

void KeyboardTrack::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    Track::eventHandler(window, event);

}

void KeyboardTrack::update(const sf::RenderWindow &window) {
    Track::update(window);

    std::vector<Key*> keys = StudioStatics::panel->getPanel()->getKeys(window);

    for (auto& n: keys) {
        auto& dNode = nodes[n->octave - Keyboard::STARTING_OCTAVE];
        if (n->AudioNode::checkStates(PLAY)) {
            // if node doesnt exit or not active;
            if (dNode.at(n->keyEnum) == nullptr || !dNode.at(n->keyEnum)->AppComponent::checkStates(ACTIVE)){
//                std::cout << n->duration;
                float timeStamp = StudioStatics::seekBar->getElapsedTime();
                audioTrack[timeStamp].emplace_back(std::make_unique<DrawableAudioNode>(timeStamp, *n, trackColor));
                dNode.at(n->keyEnum) = audioTrack[timeStamp].back().get();
            }
        }
        // if node exists and active
        else if (dNode.at(n->keyEnum) && dNode.at(n->keyEnum)->AppComponent::checkStates(ACTIVE)){
            dNode.at(n->keyEnum)->setState(ACTIVE, false);
        }
    }
}

//void KeyboardTrack::updateTrack(const std::vector<AudioNode> &keyPressed) {
//
//
//}
