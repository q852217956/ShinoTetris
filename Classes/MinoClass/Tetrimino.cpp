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
    auto tetrimino = Tetrimino_I::create();
    return tetrimino;
}

void Tetrimino::isMoveable(DIRECTION direction) {
//    根据direction选择处理方式，返回处理好的坐标
//    direction枚举定义在Direction.h头文件
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
//    返回相对坐标后处理成真实的坐标
//    消息发送
    auto isMoveableEvent = new EventCustom("isMoveable");
    isMoveableEvent -> setUserData(&(this -> posToMove));
    auto eventDispatcher = Director::getInstance() -> getEventDispatcher();
    eventDispatcher -> dispatchEvent(isMoveableEvent);
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