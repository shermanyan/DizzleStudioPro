//
// Created by Sherman Yan on 2/17/23.
//

#include "Squircle.h"
Squircle::Squircle(): Squircle({50,50},0){}

Squircle::Squircle(const sf::Vector2f& size, float radius):
Squircle(size, {radius,radius,radius,radius},sf::Color::White){}

Squircle::Squircle(const sf::Vector2f& size, const float (&radii)[4]):
Squircle(size, radii,sf::Color::White){}

Squircle::Squircle(const sf::Vector2f& size, float radius, const sf::Color& color):
Squircle(size, {radius,radius,radius,radius},sf::Color::White) {}

Squircle::Squircle(const sf::Vector2f &size, const float (&radii)[4], const sf::Color &color): size(size) {

    setRadius(radii);
    refresh();
    setFillColor(color);
}


void Squircle::setupCorners() {

    // [0 - topLeft], [1 - topRight], [2 - bottomRight], [3 - bottomLeft]

    for (int i = 0; i < 4; ++i) {
        corners[i].setRadius(radii[i]);
        corners[i].setOrigin(radii[i],radii[i]);
    }

    corners[0].setPosition({radii[0], radii[0]});
    corners[1].setPosition({size.x - radii[1], radii[1]});
    corners[3].setPosition({radii[3], size.y - radii[3]});
    corners[2].setPosition({size.x - radii[2], size.y - radii[2]});
}

void Squircle::setupBody() {

    body.setPointCount(8);

    // [0 - topLeft}
    body.setPoint(0, {0,radii[0]});
    body.setPoint(1, {radii[0],0});
    //[1 - topRight]
    body.setPoint(2, {size.x-radii[1],0});
    body.setPoint(3, {size.x,radii[1]});
    //[2 - bottomRight]
    body.setPoint(4, {size.x,size.y-radii[2]});
    body.setPoint(5, {size.x-radii[2],size.y});
    //[3 - bottomLeft]
    body.setPoint(6, {radii[3],size.y});
    body.setPoint(7, {0,size.y-radii[3]});

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
    setupCorners();
    setupBody();
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

sf::Color Squircle::getFillColor() const{
    return body.getFillColor();
}

void Squircle::setRadius(float radius) {
    setRadius({radius,radius,radius,radius});
}
void Squircle::setRadius(const float (&radii)[4]) {
    for (int i = 0; i < 4 ; ++i) {
        this->radii[i] = radii[i];
    }
    refresh();
}

float Squircle::getRadius() {
    return std::max({radii[0], radii[1], radii[2], radii[3]});
}

sf::Vector2f Squircle::getSize() const {
    return size;
}

sf::FloatRect Squircle::getGlobalBounds() const {
    return getTransform().transformRect(body.getGlobalBounds());
}

sf::FloatRect Squircle::getLocalBounds() const {
    return body.getLocalBounds();
}





