//
//  Tetrimino_Z.cpp
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#include "Tetrimino_Z.hpp"

USING_NS_CC;

Tetrimino_Z *Tetrimino_Z::create() {
	//    静态工厂函数，不用管
	Tetrimino_Z *tetrimino = new(std::nothrow) Tetrimino_Z();
	if (tetrimino && tetrimino->init()) {
		tetrimino->autorelease();
		return tetrimino;
	}
	else {
		delete tetrimino;
		tetrimino = nullptr;
		return nullptr;
	}
}

bool Tetrimino_Z::init() {
	//    初始化写在这里
	//    包括确定方块姿势、给mino坐标赋值等
	this->totalRotateType = 2;	//方块总旋转可能形状
	this->rotateType = CCRANDOM_0_1() * this->totalRotateType;	//随机初始旋转形状
	this->rotate[0] = std::array<Vec2, 4> { {Vec2(1, 1), Vec2(0, 0), Vec2(-1, -1), Vec2(0, -2)}};
	this->rotate[1] = std::array<Vec2, 4> { {Vec2(-1, -1), Vec2(0, 0), Vec2(1, 1), Vec2(0, 2)}};
	switch (this->rotateType)
	{
	case 0:
		mino[0] = Mino::create(Vec2(15, 4));
		mino[1] = Mino::create(Vec2(15, 5));
		mino[2] = Mino::create(Vec2(14, 5));
		mino[3] = Mino::create(Vec2(15, 6));
		break;
	case 1:
		mino[0] = Mino::create(Vec2(15, 5));
		mino[1] = Mino::create(Vec2(14, 5));
		mino[2] = Mino::create(Vec2(14, 4));
		mino[3] = Mino::create(Vec2(13, 4));
		break;
	default:
		break;
	}
	return true;
}

std::array<Vec2, 4> Tetrimino_Z::isRotateable() {
	//    返回旋转后的位置
	for (int i = 0; i < 4; ++i)
		this->posToMove[i] = this->mino[i]->getPos() + this->rotate[this->rotateType][i];
	this->rotateType = (this->rotateType + 1) % this->totalRotateType;
	return this->posToMove;
}