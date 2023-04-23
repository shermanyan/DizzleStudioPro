//
// Created by Sherman Yan on 4/14/23.
//

#include "Layer.h"

Layer::Layer() {
    setState(SELECTED,true);
    Position::right(track,label,10);

}
Layer::Layer(PanelTypeEnum panelType): Layer() {
    label.setTrack(panelType);
}

void Layer::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

    if (checkStates(SELECTED)) {
        label.eventHandler(window, event);
        track.eventHandler(window, event);

        if (event.KeyPressed && label.getTrackType() == KEYBOARD &&  instrumentPanel->getActivePanel()  == KEYBOARD) {
            auto *panel = dynamic_cast<KeyboardPanel *>(instrumentPanel->getPanel());
            SoundKeyPair num = panel->getKeyPressed(window);
            if (num.keyEnum != NULL_KEY)
                std::cout << num.octave  << ":" << num.keyEnum << " ";
        }
    }

}

void Layer::update(const sf::RenderWindow &window) {
    if(checkStates(SELECTED)) {
        label.update(window);
        track.update(window);
    }
}

void Layer::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    states.transform *= getTransform();
    target.draw(label,states);
    target.draw(track,states);

}

void Layer::setChildrenTransform(const sf::Transform &transform) {
    label.setParentTransform(transform);
    track.setParentTransform(transform);
}

void Layer::setTrackColor(const sf::Color &color) {
    label.setTrackColor(color);
}

void Layer::setTrack(PanelTypeEnum type) {
    label.setTrack(type);
}

sf::FloatRect Layer::getGlobalBounds() const {
    sf::FloatRect bounds = label.getGlobalBounds();
    bounds.width += 10 + track.getGlobalBounds().width;

    return getTransform().transformRect(bounds);
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


