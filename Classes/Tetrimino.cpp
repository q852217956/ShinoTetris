//
//  Tetrimino.cpp
//  HelloCpp
//
//  Created by shino on 16/7/16.
//
//

#include "Tetrimino.hpp"
#include "Tetriminos.h"

USING_NS_CC;

Tetrimino *Tetrimino::create() {
    int x = CCRANDOM_0_1() * 7;
//    x = 0;
    void *tetrimino;
    switch (x)
    {
        case 0:
            tetrimino = Tetrimino_I::create();
            return (Tetrimino_I*)tetrimino;
            break;
        case 1:
            tetrimino = Tetrimino_J::create();
            return (Tetrimino_J*)tetrimino;
            break;
        case 2:
            tetrimino = Tetrimino_L::create();
            return (Tetrimino_L*)tetrimino;
            break;
        case 3:
            tetrimino = Tetrimino_O::create();
            return (Tetrimino_O*)tetrimino;
            break;
        case 4:
            tetrimino = Tetrimino_S::create();
            return (Tetrimino_S*)tetrimino;
            break;
        case 5:
            tetrimino = Tetrimino_T::create();
            return (Tetrimino_Z*)tetrimino;
            break;
        case 6:
            tetrimino = Tetrimino_Z::create();
            return (Tetrimino_Z*)tetrimino;
            break;
        default:
            return nullptr;
            break;
    }
}

void Tetrimino::isMoveable(DIRECTION direction) {
    void *event;
    switch (direction) {
        case DIRECTION::LEFT :
            for (int i = 0; i < 4;++i) {
                this->posToMove[i] = Vec2(this->mino[i]->pos.x, this->mino[i]->pos.y - 1);
            }
            event = new EventCustom("MoveEvent");
            break;
        case DIRECTION::RIGHT :
            for (int i = 0; i < 4;++i) {
                this->posToMove[i] = Vec2(this->mino[i]->pos.x, this->mino[i]->pos.y + 1);
            }
            event = new EventCustom("MoveEvent");
            break;
        case DIRECTION::DOWN :
            for (int i = 0; i < 4;++i) {
                this->posToMove[i] = Vec2(this->mino[i]->pos.x - 1, this->mino[i]->pos.y);
            }
            event = new EventCustom("DownEvent");
            break;
        case DIRECTION::ROTATE :
            auto rotatePos = this -> isRotateable();
            for (int i = 0; i < 4; i++) {
                this -> posToMove[i] = rotatePos[i];
            }
            event = new EventCustom("MoveEvent");
            break;
    }
    for (int i = 0; i < 4;++i)
        this->realPosToMove[i] = this->posToMove[i] * 60 + Vec2(30 , 30) + Vec2(60 , 100);
    auto controlEvent = (EventCustom*)event;
    controlEvent -> setUserData(&this -> realPosToMove);
    Director::getInstance() -> getEventDispatcher() -> dispatchEvent(controlEvent);
    delete controlEvent;
}

void Tetrimino::move() {
    for (int i = 0; i < 4; i++) {
        auto action = Place::create(this -> realPosToMove[i]);
        this -> mino[i] -> runAction(action);
    }
}