//
// Created by Brandon Hargitay on 5/1/23.
//

#include "SplashScreen.h"

SplashScreen::SplashScreen() {
    setState(SELECTED, false);
    setUpText();
    setUpTextures();
    fallDuration = 3.0f; // Set the desired duration for the fall animation (in seconds)

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
    credits.setString("Created By: Brandon Hargitay & Sherman Yan");
    credits.setPosition(2000 - credits.getLocalBounds().width -30, 1125 - 50);

    pro.setFont(Fonts::getFont(NUNITO_BOLD));
    pro.setString("PRO");
    pro.setFillColor({167, 42, 54});
    pro.setCharacterSize(100);
    pro.setPosition({dizzleStudio.getPosition().x + dizzleStudio.getGlobalBounds().width + 50, -pro.getGlobalBounds().height - 150});
    initialDizzleStudioPosition = dizzleStudio.getPosition();
}

void SplashScreen::setUpTextures() {
    sprite.setTexture(Textures::getTexture(AUDIOBARS));
    sprite.setSize({2000,500});
    sprite.setPosition(0, 640);

}

void SplashScreen::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    if(event.type == sf::Event::MouseButtonPressed && MouseEvents::isClick(startButton.getGlobalBounds(), window)){
        setState(SELECTED, true);
        std::cout << "STATE";
    }
}

void SplashScreen::update(const sf::RenderWindow &window) {
    if(checkStates(SELECTED)){
        fade(3);
        fall();
    }
}

void SplashScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();

    target.draw(sprite, states);
    target.draw(dizzleStudio, states);
    target.draw(startButton, states);
    target.draw(credits, states);
    target.draw(pro, states);
}

void SplashScreen::fade(float duration) {
    float elapsedTime = fadeClock.getElapsedTime().asSeconds();

    if (elapsedTime >= duration) {
        return;
    }

    int newAlpha = static_cast<int>(255 - (255 * (elapsedTime / duration)));

    sf::Color currentColor = credits.getFillColor();
    currentColor.a = newAlpha;
    credits.setFillColor(currentColor);

}

void SplashScreen::fall() {
    float elapsedTime = fallClock.getElapsedTime().asSeconds();

    if (elapsedTime >= fallDuration) {
        return; // Stop falling when the specified duration has passed
    }

    // Calculate the new position of pro based on the elapsed time and fall duration
    float startY = -pro.getGlobalBounds().height - 150; // Set the desired start y-coordinate for pro
    float targetY = dizzleStudio.getPosition().y;
    float currentY = startY + ((targetY - startY) * (elapsedTime / fallDuration));
    pro.setPosition({initialDizzleStudioPosition.x + dizzleStudio.getGlobalBounds().width + 50, currentY});

    // Move dizzleStudio horizontally while pro is falling
    float movementDistance = 60; // Set the desired movement distance for dizzleStudio
    float currentX = initialDizzleStudioPosition.x - movementDistance * (1 - (elapsedTime / fallDuration));
    dizzleStudio.setPosition({currentX, dizzleStudio.getPosition().y});
}


