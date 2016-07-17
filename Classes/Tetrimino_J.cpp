//
//  Tetrimino_J.cpp
//  HelloCpp
//
//  Created by shino on 16/7/16.
//
//

#include "Tetrimino_J.hpp"

USING_NS_CC;

Tetrimino_J *Tetrimino_J::create() {
    Tetrimino_J *tetrimino = new(std::nothrow) Tetrimino_J();
    if (tetrimino && tetrimino->init()) {
        return tetrimino;
    }
    else {
        delete tetrimino;
        tetrimino = nullptr;
        return nullptr;
    }
}

bool Tetrimino_J::init() {
    this->totalRotateType = 4;
    this->rotateType = CCRANDOM_0_1() * this->totalRotateType;
    this->rotate[0] = std::array<Vec2, 4> { {Vec2(1, 1), Vec2(0, 0), Vec2(-1, -1), Vec2(-2, 0)}};
    this->rotate[1] = std::array<Vec2, 4> { {Vec2(1, -1), Vec2(0, 0), Vec2(-1, 1), Vec2(0, 2)}};
    this->rotate[2] = std::array<Vec2, 4> { {Vec2(-1, -1), Vec2(0, 0), Vec2(1, 1), Vec2(2, 0)}};
    this->rotate[3] = std::array<Vec2, 4> { {Vec2(-1, 1), Vec2(0, 0), Vec2(1, -1), Vec2(0, -2)}};
    switch (this->rotateType)
    {
        case 0:
            mino[0] = Mino::create(Vec2(4, 15));
            mino[1] = Mino::create(Vec2(5, 15));
            mino[2] = Mino::create(Vec2(6, 15));
            mino[3] = Mino::create(Vec2(6, 14));
            break;
        case 1:
            mino[0] = Mino::create(Vec2(5, 15));
            mino[1] = Mino::create(Vec2(5, 14));
            mino[2] = Mino::create(Vec2(5, 13));
            mino[3] = Mino::create(Vec2(4, 13));
            break;
        case 2:
            mino[0] = Mino::create(Vec2(4, 15));
            mino[1] = Mino::create(Vec2(4, 14));
            mino[2] = Mino::create(Vec2(5, 14));
            mino[3] = Mino::create(Vec2(6, 14));
            break;
        case 3:
            mino[0] = Mino::create(Vec2(5, 15));
            mino[1] = Mino::create(Vec2(4, 15));
            mino[2] = Mino::create(Vec2(4, 14));
            mino[3] = Mino::create(Vec2(4, 13));
            break;
        default:
            break;
    }
    return true;
}

std::array<Vec2, 4> Tetrimino_J::isRotateable() {
    for (int i = 0; i < 4; ++i)
        this->posToMove[i] = this->mino[i]->pos + this->rotate[this->rotateType][i];
    this->rotateType = (this->rotateType + 1) % this->totalRotateType;
    return this->posToMove;
}