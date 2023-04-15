//
// Created by Sherman Yan on 2/17/23.
//

#include "Squircle.h"
Squircle::Squircle(): Squircle({50,50},25){}

Squircle::Squircle(const sf::Vector2f& size, float radius):Squircle(size, radius,sf::Color::White){}

Squircle::Squircle(const sf::Vector2f& size, float radius, const sf::Color& color):radius(radius), size(size) {

    refresh();
    setFillColor(color);
}

void Squircle::setupCorners() {

    for (int i = 0; i < 4; ++i) {
        corners[i].setRadius(radius);
        corners[i].setOrigin(radius,radius);
    }

    corners[0].setPosition(radius,radius);
    corners[1].setPosition(radius,size.y - radius);
    corners[2].setPosition(size.x - radius, radius);
    corners[3].setPosition(size.x - radius, size.y - radius);
}


void Squircle::setupBody() {

    body.setPointCount(8);

    body.setPoint(0, {0,radius});
    body.setPoint(1, {radius,0});
    body.setPoint(2, {size.x-radius,0});
    body.setPoint(3, {size.x,radius});
    body.setPoint(4, {size.x,size.y-radius});
    body.setPoint(5, {size.x-radius,size.y});
    body.setPoint(6, {radius,size.y});
    body.setPoint(7, {0,size.y-radius});

}

void Squircle::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    states.transform *= getTransform();

    for (int i = 0; i < 4; ++i) {
        target.draw(corners[i],states);
    }
    target.draw(body,states);
}

void Squircle::setSize(const sf::Vector2f &size) {
    this->size = size;
    refresh();
}

void Squircle::refresh() {
    setupBody();
    setupCorners();
}

void Squircle::setSize(float x, float y) {
    setSize({x,y});
}

void Squircle::setFillColor(const sf::Color &color) {

    for (int i = 0; i < 4; ++i) {
        corners[i].setFillColor(color);
    }
    body.setFillColor(color);
}

void Squircle::setRadius(float radius) {
    this->radius = radius;
    refresh();
}

float Squircle::getRadius() {
    return radius;
}

sf::Vector2f Squircle::getSize() {
    return size;
}

sf::FloatRect Squircle::getGlobalBounds() const {
    return getTransform().transformRect(body.getGlobalBounds());
}

sf::FloatRect Squircle::getLocalBounds() const {
    return body.getLocalBounds();
}

