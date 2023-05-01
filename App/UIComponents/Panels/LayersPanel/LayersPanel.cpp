//
// Created by Sherman Yan on 4/19/23.
//

#include "LayersPanel.h"

void LayersPanel::setChildrenTransform(const sf::Transform &transform) {
    for (auto&l:layers) {
        l.setParentTransform(transform);
    }
    trackControls.setParentTransform(transform);
}

LayersPanel::LayersPanel() {
    StudioStatics::seekBar = &seek;

    background = {{1960, 600},20, {121,121,121}};

    for (int i = 0; i < 4; ++i) {
        layers.emplace_back();
        layers.back().setTrackColor(trackColors[i]);
    }

    layers.front().setPosition(20,70);
    for (int i = 1; i < layers.size(); i++) {
        Position::center(layers[i],layers[i-1]);
        Position::bottom(layers[i],layers[i-1],10);
    }

    layers[0].setTrack(KEYBOARD);
    layers[1].setTrack(DRUMPAD);
    layers[2].setTrack(AUDIO);
    layers[3].setTrack(VOCAL);


    seek.setSize({10,560});
    seek.setDuration(20);
    seek.setLength(1530);
    seek.setFillColor({185,185,185});
    seek.setPosition(410,25);
    seek.setRadius(5);

    timeBar.setDuration(seek.getDuration());
    DrawableAudioNode::setDurationScale(seek.getDuration());

    Position::alignRight(timeBar,layers[0]);
    Position::top(timeBar,layers[0],10);

    trackControls.setPosition(20,20);
}

void LayersPanel::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

    seek.eventHandler(window,event);
    timeBar.eventHandler(window,event);
    trackControls.eventHandler(window,event);

    for (auto&l:layers) {
        l.eventHandler(window, event);
        if(l.checkStates(SELECTED)) {
            for (auto &l2: layers) {
                if (&l2 != &l) {
                    l2.setState(SELECTED, false);
                }
            }
        }
    }



    if(event.KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket)) {
        int duration =  timeBar.getDuration() + 1;
        timeBar.setDuration(duration);
        seek.setDuration(duration);
        DrawableAudioNode::setDurationScale(duration);
    }
    else if (event.KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket)) {
        int duration =  timeBar.getDuration() -1;
        timeBar.setDuration(duration);
        seek.setDuration(duration);
        DrawableAudioNode::setDurationScale(duration);
    }

}

void LayersPanel::update(const sf::RenderWindow &window) {
    seek.update(window);
    timeBar.update(window);
    trackControls.update(window);

    for (auto&l:layers) {
        l.update(window);
        l.setState(RECORDING,trackControls.checkStates(RECORDING));
    }

    if(trackControls.checkStates(RECORDING)){
        if (seek.checkStates(STOP))
            trackControls.setState(RECORDING,false);
        else if (!seek.checkStates(PLAY)){
            seek.play();
        }
    }
    else if(trackControls.checkStates(PLAY)) {
        seek.setState(LOOP,trackControls.checkStates(LOOP));

        if(seek.checkStates(STOP)) {
            trackControls.setState(PLAY, false);
        }
        else if (!seek.checkStates(PLAY)) {
            seek.play();
        }
    } else if (seek.checkStates(PLAY)){
        seek.pause();
    }


}

void LayersPanel::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(background,states);

    for (auto&l:layers) {
        target.draw(l,states);
    }

    target.draw(timeBar,states);
    target.draw(seek,states);
    target.draw(trackControls,states);
}
