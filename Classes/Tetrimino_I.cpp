//
//  Tetrimino_I.cpp
//  HelloCpp
//
//  Created by shino on 16/7/16.
//
//

#include "Tetrimino_I.hpp"

USING_NS_CC;

Tetrimino_I *Tetrimino_I::create() {
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
    this->totalRotateType = 2;	//方块总旋转可能形状
    this->rotateType = CCRANDOM_0_1() * this->totalRotateType;	//随机初始旋转形状
    this->rotate[0] = std::array<Vec2, 4> { {Vec2(1, 1), Vec2(0, 0), Vec2(-1, -1), Vec2(-2, -2)}};
    this->rotate[1] = std::array<Vec2, 4> { {Vec2(-1, -1), Vec2(0, 0), Vec2(1, 1), Vec2(2, 2)}};
    switch (this->rotateType)
    {
        case 0:
            mino[0] = Mino::create(Vec2(3, 15));
            mino[1] = Mino::create(Vec2(4, 15));
            mino[2] = Mino::create(Vec2(5, 15));
            mino[3] = Mino::create(Vec2(6, 15));
            break;
        case 1:
            mino[0] = Mino::create(Vec2(5, 15));
            mino[1] = Mino::create(Vec2(5, 14));
            mino[2] = Mino::create(Vec2(5, 13));
            mino[3] = Mino::create(Vec2(5, 12));
            break;
        default:
            break;
    }
    return true;
}

std::array<Vec2, 4> Tetrimino_I::isRotateable() {
    for (int i = 0; i < 4; ++i)
        this->posToMove[i] = this->mino[i]->getPosition() + this->rotate[this->rotateType][i];
    this->rotateType = (this->rotateType + 1) % this->totalRotateType;
    return this->posToMove;
}