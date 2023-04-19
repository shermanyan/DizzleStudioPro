//
// Created by Sherman Yan on 12/9/22.
//

#ifndef POSITION_H
#define POSITION_H

#include <SFML/Graphics.hpp>

class Position {

public:
    template<class T, class S>
    static void left( T& self,const S& ref, float spacing = 0);
    template<class T, class S>
    static void right( T& self,const S& ref, float spacing = 0);
    template<class T, class S>
    static void top( T& self, const S& ref, float spacing = 0);
    template<class T, class S>
    static void bottom( T& self, const S& ref, float spacing = 0);

    template<class T, class S>
    static void alignLeft( T& self,const S& ref);
    template<class T, class S>
    static void alignRight( T& self,const S& ref);
    template<class T, class S>
    static void alignTop( T& self, const S& ref);
    template<class T, class S>
    static void alignBottom( T& self, const S& ref);

    template<class T, class S>
    static void center(T& self,const S& ref);
    template<class T, class S>
    static void centerText(S& text, const T &ref);
};

#include "Position.cpp"

#endif //POSITION_H
