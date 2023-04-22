//
// Created by Sherman Yan on 4/14/23.
//

#include "Layer.h"

Layer::Layer() {
    setState(SELECTED,false);
}
Layer::Layer(PanelTypeEnum panelType): Layer() {
    label.setTrack(panelType);
}

void Layer::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

    label.eventHandler(window,event);

    if (event.MouseButtonPressed && instrumentPanel->getActivePanel() ==  KEYBOARD) {
        auto *panel = dynamic_cast<KeyboardPanel *>(instrumentPanel->getPanel());
        SoundKeys num = panel->getKeyPressed(window).second;
        if (num != NULL_KEY)
            std::cout << num << " ";

    }

}

void Layer::update(const sf::RenderWindow &window) {
    if(checkStates(SELECTED)) {
        label.update(window);
    }
}

void Layer::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    states.transform *= getTransform();
    target.draw(label,states);

}

void Layer::setChildrenTransform(const sf::Transform &transform) {
    label.setParentTransform(transform);
}

void Layer::setTrackColor(const sf::Color &color) {
    label.setTrackColor(color);
}

void Layer::setTrack(PanelTypeEnum type) {
    label.setTrack(type);
}

sf::FloatRect Layer::getGlobalBounds() const {
    return getTransform().transformRect(label.getGlobalBounds());
}

sf::FloatRect Layer::getLocalBounds() const {
    return label.getLocalBounds();
}

PanelTypeEnum Layer::getTrackType() const {
    return label.getTrackType();
}

void Layer::setInstrumentPanel(DynamicInstrumentPanel *instrumentPanel) {
    Layer::instrumentPanel = instrumentPanel;
}


