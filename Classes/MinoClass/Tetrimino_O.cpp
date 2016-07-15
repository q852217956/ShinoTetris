//
//  Tetrimino_O.cpp
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#include "Tetrimino_O.hpp"

USING_NS_CC;

Tetrimino_O *Tetrimino_O::create() {
	//    ��̬�������������ù�
	Tetrimino_O *tetrimino = new(std::nothrow) Tetrimino_O();
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

bool Tetrimino_O::init() {
	//    ��ʼ��д������
	//    ����ȷ���������ơ���mino���긳ֵ��
	this->totalRotateType = 1;	//��������ת������״
	this->rotateType = 0;	//�����ʼ��ת��״
	mino[0] = Mino::create(Vec2(15, 4));
	mino[1] = Mino::create(Vec2(15, 5));
	mino[2] = Mino::create(Vec2(14, 4));
	mino[3] = Mino::create(Vec2(14, 5));
	return true;
}

std::array<Vec2, 4> Tetrimino_O::isRotateable() {
	//    ������ת���λ��
	for (int i = 0; i < 4; ++i)
		this->posToMove[i] = this->mino[i]->getPos() + this->rotate[this->rotateType][i];
	this->rotateType = (this->rotateType + 1) % this->totalRotateType;
	return this->posToMove;
}