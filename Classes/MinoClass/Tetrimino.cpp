//
//  Tetrimino.cpp
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#include "Tetrimino.hpp"
#include "Tetriminos.h"

USING_NS_CC;

Tetrimino *Tetrimino::create() {
//    随机生成Tetrimino,确定子类后调用该子类的create方法即可
//    以Tetrimino_I为例
	int x = CCRANDOM_0_1() * 7;
	switch (x)
	{
	case 0:
		auto tetrimino = Tetrimino_I::create();
		return tetrimino;
		break;
	case 1:
		auto tetrimino = Tetrimino_J::create();
		return tetrimino;
		break;
	case 2:
		auto tetrimino = Tetrimino_L::create();
		return tetrimino;
		break;
	case 3:
		auto tetrimino = Tetrimino_O::create();
		return tetrimino;
		break;
	case 4:
		auto tetrimino = Tetrimino_S::create();
		return tetrimino;
		break;
	case 5:
		auto tetrimino = Tetrimino_T::create();
		return tetrimino;
		break;
	case 6:
		auto tetrimino = Tetrimino_Z::create();
		return tetrimino;
		break;
	default:
		break;
	}
    
}

void Tetrimino::isMoveable(DIRECTION direction) {
//    根据direction选择处理方式，返回处理好的坐标
//    direction枚举定义在Direction.h头文件
    switch (direction) {
        case DIRECTION::LEFT :
			for (int i = 0; i < 4;++i)
				this->posToMove[i] = Vec2(this->mino[i]->getPos().x, this->mino[i]->getPos().y - 1);
            break;
        case DIRECTION::RIGHT :
			for (int i = 0; i < 4;++i)
				this->posToMove[i] = Vec2(this->mino[i]->getPos().x, this->mino[i]->getPos().y + 1);
            break;
        case DIRECTION::ROTATE :
            this -> isRotateable();
            break;
        case DIRECTION::DOWN :
			for (int i = 0; i < 4;++i)
				this->posToMove[i] = Vec2(this->mino[i]->getPos().x - 1, this->mino[i]->getPos().y);
            break;
    }
	for (int i = 0; i < 4;++i)
		this->posToMove_Real[i] = this->posToMove[i] * 60 + Vec2(30 , 30) + Vec2(60 , 100);

//    返回相对坐标后处理成真实的坐标
//    消息发送
    auto isMoveableEvent = new EventCustom("isMoveable");
    isMoveableEvent -> setUserData(&(this ->posToMove_Real));
    auto eventDispatcher = Director::getInstance() -> getEventDispatcher();
    eventDispatcher -> dispatchEvent(isMoveableEvent);
}

bool Tetrimino::move(DIRECTION direction) {	//待改
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