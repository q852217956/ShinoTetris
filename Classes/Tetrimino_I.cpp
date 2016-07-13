//
//  Tetrimino_I.cpp
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#include "Tetrimino_I.hpp"

USING_NS_CC;

Tetrimino_I *Tetrimino_I::cerate() {
    Tetrimino_I *tetrimino = new(std::nothrow) Tetrimino_I();
    if (tetrimino && tetrimino -> init()) {
        tetrimino -> autorelease();
        return tetrimino;
    } else {
        delete tetrimino;
        tetrimino = nullptr;
        return nullptr;
    }
}

bool Tetrimino_I::init() {
    
}