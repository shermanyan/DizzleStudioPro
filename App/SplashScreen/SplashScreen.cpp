//
// Created by Brandon Hargitay on 5/1/23.
//

#include "SplashScreen.h"

SplashScreen::SplashScreen() {
    setState(SELECTED, false);
    musicMixer.setState(HOVERED,false);
    musicPlayer.setState(HOVERED,false);

    setUpText();
    setUpTextures();
    duration = 1.0f;
}



void SplashScreen::setUpTextures() {
    sprite.setTexture(Textures::getTexture(AUDIOBARS));
    sprite.setSize({2000,1600});
    sprite.setPosition(0, 630);

    musicMixer.setTexture(Textures::getTexture(MUSICMIXER));
    musicMixer.setSize({1000,600});
    musicMixer.setPosition(15, 1490);

    musicPlayer.setTexture(Textures::getTexture(MUSICPLAYER));
    musicPlayer.setSize({1000,600});
    musicPlayer.setPosition(975, 1490);

}
void SplashScreen::setUpText() {

    startButton.setFont(Fonts::getFont(NUNITO_BOLD));
    startButton.setString("Start");
    startButton.setCharacterSize(55);
    startButton.setOrigin(startButton.getLocalBounds().width/2, startButton.getLocalBounds().height/2);
    startButton.setFillColor({151, 151,151});
    startButton.setPosition(1000, 563);

    dizzleStudio.setFont(Fonts::getFont(NUNITO_BOLD));
    dizzleStudio.setCharacterSize(100);
    dizzleStudio.setPosition({450,390});
    dizzleStudio.setString("Dizzle Studio");
    dizzleStudio.setFillColor({175, 143, 54});
    Position::center(dizzleStudio,startButton);
    Position::top(dizzleStudio, startButton, 50);

    credits.setFont(Fonts::getFont(NUNITO_BOLD));
    credits.setFillColor({151, 151,151});
    credits.setString("Created By: Brandon Hargitay & Sherman Yan");
    credits.setPosition(2000 - credits.getLocalBounds().width -30, 1125 - 50);

    pro.setFont(Fonts::getFont(NUNITO_BOLD));
    pro.setString("PRO");
    pro.setFillColor({167, 42, 54});
    pro.setCharacterSize(100);
    pro.setPosition({dizzleStudio.getPosition().x + dizzleStudio.getGlobalBounds().width + 50, -1125});
    initialDizzleStudioPosition = dizzleStudio.getPosition();

    welcome.setFont(Fonts::getFont(NUNITO_BOLD));
    welcome.setString("Welcome");
    welcome.setCharacterSize(100);
    welcome.setFillColor({175, 143, 54});
    welcome.setPosition(50, 1180);

    getStarted.setFont(Fonts::getFont(NUNITO_BOLD));
    getStarted.setString("Get Started");
    getStarted.setCharacterSize(55);
    getStarted.setFillColor({151, 151,151});
    getStarted.setPosition(80, 1310);

}

void SplashScreen::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    if(event.type == sf::Event::MouseButtonPressed && MouseEvents::isClick(startButton.getGlobalBounds(), window)){
        setState(SELECTED, true);
        animationClock.restart(); // Start the clock when the start button is clicked
        std::cout << "START CLICKED";

    }
    if(MouseEvents::isHover(musicMixer.getGlobalBounds(), window)){
        musicMixer.setState(HOVERED, true);
    }else{
        musicMixer.setState(HOVERED, false);
    }

    if(MouseEvents::isHover(musicPlayer.getGlobalBounds(), window)){
        musicPlayer.setState(HOVERED, true);
    }else{
        musicPlayer.setState(HOVERED, false);
    }

}

void SplashScreen::update(const sf::RenderWindow &window) {
    if(checkStates(SELECTED)){
        fall();
        transition();
    }
}

void SplashScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();

    target.draw(dizzleStudio, states);
    target.draw(startButton, states);
    target.draw(pro, states);
    target.draw(sprite, states);
    target.draw(credits, states);

    target.draw(welcome, states);
    target.draw(getStarted,states);

    if(musicPlayer.checkStates(HOVERED)){
        states.transform.scale(1.1,1.1);
        target.draw(musicPlayer,states);
    }else{
        states.transform.scale(1,1);
        target.draw(musicPlayer,states);
    }

    if(musicMixer.checkStates(HOVERED)){
        states.transform.scale(1.1,1.1);
        target.draw(musicMixer,states);
    }else{
        states.transform.scale(1,1);
        target.draw(musicMixer,states);
    }

}


void SplashScreen::fall() {
    float elapsedTime = animationClock.getElapsedTime().asSeconds();

    if (elapsedTime >= duration) {
        return;
    }

    // Calculate the new position of pro based on the elapsed time and fall duration
    float startY = -pro.getGlobalBounds().height - 180;
    float targetY = dizzleStudio.getPosition().y;
    float currentY = startY + ((targetY - startY) * (elapsedTime / duration));

    // Gradually move dizzleStudio horizontally according to the fallDuration
    float movementDistance = -160;
    float currentX = initialDizzleStudioPosition.x + (movementDistance * (elapsedTime / duration));
    dizzleStudio.setPosition({currentX, dizzleStudio.getPosition().y});

    // Set the pro position based on the current dizzleStudio position
    pro.setPosition({dizzleStudio.getPosition().x + dizzleStudio.getGlobalBounds().width + 50, currentY});
}

void SplashScreen::transition() {
    float elapsedTime = animationClock.getElapsedTime().asSeconds();

    if(elapsedTime >= duration + 0.5){
        if(sprite.getPosition().y > -450){
            moveUp({0,-7});
        }else{
            toggleState(SELECTED);
        }
    }
}

void SplashScreen::moveUp(const sf::Vector2f & offset) {
    sprite.move(offset);
    welcome.move(offset);
    getStarted.move(offset);
    musicMixer.move(offset);
    musicPlayer.move(offset);
}

void SplashScreen::fade() {
    float elapsedTime = animationClock.getElapsedTime().asSeconds();

    if (elapsedTime > duration) {
        return;
    }

    int newAlpha = static_cast<int>(255 - (255 * (elapsedTime / duration)));

    if (newAlpha < 5){
        newAlpha = 0;
    }
    sf::Color currentColor = credits.getFillColor();
    currentColor.a = newAlpha;
    credits.setFillColor(currentColor);

}
