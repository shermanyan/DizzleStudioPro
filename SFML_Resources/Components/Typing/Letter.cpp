//
// Created by Sherman Yan on 3/5/23.
//

#include "Letter.h"

Letter::Letter(){

}

Letter::Letter(char c) {
    setString(std::string(1,c));
}

Letter::Letter(const Letter &letter) {
    *this = letter;
}


