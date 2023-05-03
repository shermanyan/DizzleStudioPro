//
// Created by Sherman Yan on 4/23/23.
//

#include "KeyboardTrack.h"

KeyboardTrack::KeyboardTrack(): Track{} {

    for (int i = 0; i < KeyboardPanel::octaveCount; ++i) {
        nodes.emplace_back();
        for (int j = C; j <= As; ++j) {
            nodes.back()[SoundKeys(j)] = nullptr;
        }
    }
}


void KeyboardTrack::update(const sf::RenderWindow &window) {
    Track::update(window);

    if (checkStates(SELECTED)) {
        std::vector<Key *> keys = dynamic_cast<KeyboardPanel *>(StudioStatics::panel->getPanel())->getKeys();
        for (auto &n: keys) {
            auto &dNode = nodes[n->octave - Keyboard::STARTING_OCTAVE];
            if (n->AudioNode::checkStates(PLAY) && checkStates(RECORDING)) {
                // if node doesnt exit or not active;
                if (dNode.at(n->keyEnum) == nullptr || !dNode.at(n->keyEnum)->AppComponent::checkStates(ACTIVE)) {
//                std::cout << n->duration;
                    float timeStamp = StudioStatics::seekBar->getElapsedTime().asSeconds();
                    audioTrack[timeStamp].emplace_back(std::make_unique<DrawableAudioNode>(timeStamp, *n, trackColor));
                    dNode.at(n->keyEnum) = audioTrack[timeStamp].back().get();
                    dNode.at(n->keyEnum)->setParentTransform(getCombinedTransform());
                    dNode.at(n->keyEnum)->setState(ACTIVE, true);
                }
            }
                // if node exists and active
            else if (dNode.at(n->keyEnum) && dNode.at(n->keyEnum)->AppComponent::checkStates(ACTIVE)) {
                dNode.at(n->keyEnum)->setState(ACTIVE, false);
            }
        }
    }
}

void KeyboardTrack::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    for (auto& n: audioTrack) {
        for (auto& node: n.second) {
            node->eventHandler(window,event);

            if(node->checkStates(SELECTED)&& sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                nodes[node->getNode().octave - Keyboard::STARTING_OCTAVE].at(node->getNode().keyEnum) = nullptr;
                n.second.erase(std::find(n.second.begin(), n.second.end(), node));
            }
        }
    }
}


//void KeyboardTrack::updateTrack(const std::vector<AudioNode> &keyPressed) {
//
//
//}
