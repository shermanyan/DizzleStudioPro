//
// Created by Sherman Yan on 4/30/23.
//

#include "TrackControls.h"

TrackControls::TrackControls() {
    setState(PLAY,false);
    setState(LOOP,false);

    background.setSize(380,40);
    background.setFillColor({94,94,94});
    background.setRadius(10);

    record.setRadius(10);
    record.setFillColor({116, 14, 24});

    play.setTexture(Textures::getTexture(TRACKCONTROLS_PLAY));
    pause.setTexture(Textures::getTexture(TRACKCONTROLS_PAUSE));
    forward.setTexture(Textures::getTexture(TRACKCONTROLS_FORWARD));
    rewind.setTexture(Textures::getTexture(TRACKCONTROLS_REWIND));
    loop.setTexture(Textures::getTexture(TRACKCONTROLS_LOOP));

    play.setWidth(22);
    pause.setWidth(22);
    forward.setWidth(30);
    rewind.setWidth(30);
    loop.setWidth(30);

    Position::center(play,background);
    Position::center(pause,play);
    Position::center(forward,play);
    Position::center(rewind,play);
    Position::center(loop,background);
    Position::right(forward,play,8);
    Position::left(rewind,play,16);
    Position::left(loop,rewind,100);

    Position::center(record,background);
    Position::alignRight(record,background);
    record.setPosition(record.getPosition() - sf::Vector2f {20,0});

    clock.restart();

}

void TrackControls::eventHandler(sf::RenderWindow &window, const sf::Event &event) {

    if (event.type == sf::Event::MouseButtonPressed && MouseEvents::isClick(getCombinedTransform().transformRect(record.getGlobalBounds()),window)) {
        toggleState(RECORDING);
    }else if(event.type == sf::Event::MouseButtonPressed && MouseEvents::isClick(getCombinedTransform().transformRect(play.getGlobalBounds()),window)){
        toggleState(PLAY);
    }else if(event.type == sf::Event::MouseButtonPressed && MouseEvents::isClick(getCombinedTransform().transformRect(forward.getGlobalBounds()),window)){
        forward.setTexture(Textures::getTexture(TRACKCONTROLS_FORWARD_LIGHT));
        StudioStatics::seekBar->forward(0.5);
    }else if(event.type == sf::Event::MouseButtonPressed && MouseEvents::isClick(getCombinedTransform().transformRect(rewind.getGlobalBounds()),window)){
        rewind.setTexture(Textures::getTexture(TRACKCONTROLS_REWIND_LIGHT));
        StudioStatics::seekBar->rewind(0.5);
    }
    else if(event.type == sf::Event::MouseButtonPressed && MouseEvents::isClick(getCombinedTransform().transformRect(loop.getGlobalBounds()),window)){
        toggleState(LOOP);
        if (checkStates(LOOP))
            loop.setTexture(Textures::getTexture(TRACKCONTROLS_LOOP_LIGHT));
        else
            loop.setTexture(Textures::getTexture(TRACKCONTROLS_LOOP));
    } else {
        forward.setTexture(Textures::getTexture(TRACKCONTROLS_FORWARD));
        rewind.setTexture(Textures::getTexture(TRACKCONTROLS_REWIND));
    }

}

void TrackControls::update(const sf::RenderWindow &window) {

    if(checkStates(RECORDING) && clock.getElapsedTime().asSeconds() > .5){
        clock.restart();
        record.setFillColor({190,16,32});
    }
    else if (clock.getElapsedTime().asSeconds() > .25)
        record.setFillColor({116, 14, 24});


}

void TrackControls::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(background,states);

    if(!checkStates(PLAY))
        target.draw(play,states);
    else
        target.draw(pause,states);

    target.draw(rewind,states);
    target.draw(forward,states);
    target.draw(loop,states);
    target.draw(record,states);


}
