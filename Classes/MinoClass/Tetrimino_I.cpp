//
//  Tetrimino_I.cpp
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#include "Tetrimino_I.hpp"

USING_NS_CC;

Tetrimino_I *Tetrimino_I::create() {
//    静态工厂函数，不用管
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
//    初始化写在这里
//    包括确定方块姿势、给mino坐标赋值等
	this->totalRotateType = 2;	//方块总旋转可能形状
	this->rotateType = CCRANDOM_0_1() * this->totalRotateType;	//随机初始旋转形状
	this->rotate[0] = std::array<Vec2, 4> { {Vec2(1, 1), Vec2(0, 0), Vec2(-1, -1), Vec2(-2, -2)}};
	this->rotate[1] = std::array<Vec2, 4> { {Vec2(-1, -1), Vec2(0, 0), Vec2(1, 1), Vec2(2, 2)}};
	switch (this->rotateType)
	{
	case 0:
		mino[0] = Mino::create(Vec2(15, 3));
		mino[1] = Mino::create(Vec2(15, 4));
		mino[2] = Mino::create(Vec2(15, 5));
		mino[3] = Mino::create(Vec2(15, 6));
		break;
	case 1:
		mino[0] = Mino::create(Vec2(15, 5));
		mino[1] = Mino::create(Vec2(14, 5));
		mino[2] = Mino::create(Vec2(13, 5));
		mino[3] = Mino::create(Vec2(12, 5));
		break;
	default:
		break;
	}
    return true;
}

std::array<Vec2, 4> Tetrimino_I::isRotateable() {
//    返回旋转后的位置
	for (int i = 0; i < 4; ++i)
		this->posToMove[i] = this->mino[i]->getPos() + this->rotate[this->rotateType][i];
	this->rotateType = (this->rotateType + 1) % this->totalRotateType;
    return this->posToMove;
}