//
//  Tetrimino_L.cpp
//  HelloCpp
//
//  Created by shino on 16/7/16.
//
//

#include "Tetrimino_L.hpp"

USING_NS_CC;

Tetrimino_L *Tetrimino_L::create() {
    //    静态工厂函数，不用管
    Tetrimino_L *tetrimino = new(std::nothrow) Tetrimino_L();
    if (tetrimino && tetrimino->init()) {
        //		tetrimino->autorelease();
        return tetrimino;
    }
    else {
        delete tetrimino;
        tetrimino = nullptr;
        return nullptr;
    }
}

bool Tetrimino_L::init() {
    //    初始化写在这里
    //    包括确定方块姿势、给mino坐标赋值等
    this->totalRotateType = 4;	//方块总旋转可能形状
    this->rotateType = CCRANDOM_0_1() * this->totalRotateType;	//随机初始旋转形状
    this->rotate[0] = std::array<Vec2, 4> { {Vec2(-1, -1), Vec2(0, 0), Vec2(1, 1), Vec2(0, 2)}};
    this->rotate[1] = std::array<Vec2, 4> { {Vec2(-1, 1), Vec2(0, 0), Vec2(1, -1), Vec2(2, 0)}};
    this->rotate[2] = std::array<Vec2, 4> { {Vec2(1, 1), Vec2(0, 0), Vec2(-1, -1), Vec2(0, -2)}};
    this->rotate[3] = std::array<Vec2, 4> { {Vec2(1, -1), Vec2(0, 0), Vec2(-1, 1), Vec2(-2, 0)}};
    switch (this->rotateType)
    {
        case 0:
            mino[0] = Mino::create(Vec2(4, 15));
            mino[1] = Mino::create(Vec2(5, 15));
            mino[2] = Mino::create(Vec2(6, 15));
            mino[3] = Mino::create(Vec2(4, 14));
            break;
        case 1:
            mino[0] = Mino::create(Vec2(4, 15));
            mino[1] = Mino::create(Vec2(5, 15));
            mino[2] = Mino::create(Vec2(5, 14));
            mino[3] = Mino::create(Vec2(5, 13));
            break;
        case 2:
            mino[0] = Mino::create(Vec2(6, 15));
            mino[1] = Mino::create(Vec2(4, 14));
            mino[2] = Mino::create(Vec2(5, 14));
            mino[3] = Mino::create(Vec2(6, 14));
            break;
        case 3:
            mino[0] = Mino::create(Vec2(4, 15));
            mino[1] = Mino::create(Vec2(4, 14));
            mino[2] = Mino::create(Vec2(4, 13));
            mino[3] = Mino::create(Vec2(5, 13));
            break;
        default:
            break;
    }
    return true;
}

std::array<Vec2, 4> Tetrimino_L::isRotateable() {
    //    返回旋转后的位置
    for (int i = 0; i < 4; ++i)
        this->posToMove[i] = this->mino[i]->pos + this->rotate[this->rotateType][i];
    this->rotateType = (this->rotateType + 1) % this->totalRotateType;
    return this->posToMove;
}