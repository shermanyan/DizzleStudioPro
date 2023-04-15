//
// Created by Sherman Yan on 3/20/23.
//

#include "Cursor.h"
#include <iostream>

Cursor::Cursor(): Cursor(0.5){

}

Cursor::Cursor(double interval): interval(interval) {
    setState(ACTIVE, true);
    setString('|');
    clock.restart();
}

void Cursor::update() {
    if(clock.getElapsedTime().asMicroseconds() >= interval * 1000000) {
        clock.restart();
        toggleState(ACTIVE);
    }
}

void Cursor::setCursorCharacter(char cursor) {
    setString(cursor);
}
