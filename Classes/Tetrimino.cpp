//
//  Tetrimino.cpp
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#include "Tetrimino.hpp"

USING_NS_CC;

Tetrimino *Tetrimino::create() {
    
    Tetrimino *tetrimino = new(std::nothrow) Tetrimino();
    if (tetrimino && tetrimino -> init()) {
        tetrimino -> autorelease();
        return tetrimino;
    } else {
        delete tetrimino;
        tetrimino = nullptr;
        return nullptr;
    }
}

bool Tetrimino::init() {
    for (int i = 0; i < 4; i++) {
        this -> pos[i] = this -> mino[i] -> getPos();
    }
    return true;
}

void Tetrimino::ismoveable(DIRECTION direction) {
    switch (direction) {
        case DIRECTION::LEFT :
            break;
        case DIRECTION::RIGHT :
            break;
        case DIRECTION::ROTATE :
            this -> isRotateable();
            break;
        case DIRECTION::DOWN :
            break;
    }
}

bool Tetrimino::move(DIRECTION direction) {
    if (direction == DIRECTION::DOWN) {
        if (this -> posToMove == this -> pos) {
            return false;
        }
    }
    for (int i = 0; i < 4; i++) {
        auto action = Place::create(this -> posToMove[i]);
        this -> mino[i] -> runAction(action);
    }
    return true;
}