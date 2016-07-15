//
//  Tetrimino_S.cpp
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#include "Tetrimino_S.hpp"

USING_NS_CC;

Tetrimino_S *Tetrimino_S::create() {
	//    ��̬�������������ù�
	Tetrimino_S *tetrimino = new(std::nothrow) Tetrimino_S();
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

bool Tetrimino_S::init() {
	//    ��ʼ��д������
	//    ����ȷ���������ơ���mino���긳ֵ��
	this->totalRotateType = 2;	//��������ת������״
	this->rotateType = CCRANDOM_0_1() * this->totalRotateType;	//�����ʼ��ת��״
	this->rotate[0] = std::array<Vec2, 4> { {Vec2(-1, 0), Vec2(0, 1), Vec2(1, 0), Vec2(2, 1)}};
	this->rotate[1] = std::array<Vec2, 4> { {Vec2(1, 0), Vec2(0, -1), Vec2(-1, 0), Vec2(-2, -1)}};
	switch (this->rotateType)
	{
	case 0:
		mino[0] = Mino::create(Vec2(15, 5));
		mino[1] = Mino::create(Vec2(15, 6));
		mino[2] = Mino::create(Vec2(14, 4));
		mino[3] = Mino::create(Vec2(14, 5));
		break;
	case 1:
		mino[0] = Mino::create(Vec2(15, 4));
		mino[1] = Mino::create(Vec2(14, 4));
		mino[2] = Mino::create(Vec2(14, 5));
		mino[3] = Mino::create(Vec2(13, 5));
		break;
	default:
		break;
	}
	return true;
}

std::array<Vec2, 4> Tetrimino_S::isRotateable() {
	//    ������ת���λ��
	for (int i = 0; i < 4; ++i)
		this->posToMove[i] = this->mino[i]->getPos() + this->rotate[this->rotateType][i];
	this->rotateType = (this->rotateType + 1) % this->totalRotateType;
	return this->posToMove;
}