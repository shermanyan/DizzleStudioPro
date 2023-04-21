//
// Created by Sherman Yan on 4/19/23.
//

#include "LayersPanel.h"

LayersPanel::LayersPanel() {
    background = {{1960, 600},20, {121,121,121}};

    for (int i = 0; i < 4; i++) {
        labels.emplace_back(trackColors[i]);
    }
    labels.front().setPosition(20,70);
    for (int i = 1; i < labels.size(); i++) {
        Position::center(labels[i],labels[i-1]);
        Position::bottom(labels[i],labels[i-1],10);
    }
    labels[0].setTrack(KEYBOARD);
    labels[1].setTrack(AUDIO);

}

void LayersPanel::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    for(auto& i:labels) {
        i.eventHandler(window, event);
    }
    if(instrumentPanel) {
        for (auto &i: labels) {
            if (event.type == sf::Event::MouseButtonPressed &&
            MouseEvents::isClick(getTransform().transformRect(i.getGlobalBounds()), window)) {
                panelType = i.getTrackType();
                instrumentPanel->setActivePanel(panelType);
            }
        }

        if (event.type == sf::Event::MouseButtonPressed && panelType == KEYBOARD) {
            auto *panel = dynamic_cast<KeyboardPanel *>(instrumentPanel->getPanel());
            KeyEnum num = panel->getKeyPressed(window).second;
            if (num != NULL_KEY)
                std::cout << num << " ";
        }
    }



}

void LayersPanel::update(const sf::RenderWindow &window) {
    for(auto& i:labels)
        i.update(window);

}

void LayersPanel::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    states.transform *= getTransform();
    target.draw(background,states);
    for (auto& l: labels) {
        target.draw(l,states);

    }
}

void LayersPanel::setChildrenTransform(const sf::Transform &transform) {
    for(auto& i:labels)
        i.setParentTransform(transform);
}

void LayersPanel::setInstrumentPanel(DynamicInstrumentPanel *instrumentPanel) {
    LayersPanel::instrumentPanel = instrumentPanel;
}
