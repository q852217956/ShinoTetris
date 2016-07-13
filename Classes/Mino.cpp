//
//  Mino.cpp
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#include "Mino.hpp"

USING_NS_CC;

Mino *Mino::create(Vec2 pos) {
    Mino *mino = new(std::nothrow) Mino();
    if (mino && mino -> init(pos)) {
        mino -> autorelease();
        return mino;
    } else {
        delete mino;
        mino = nullptr;
        return nullptr;
    }
}

bool Mino::init(Vec2 pos) {
    if (!Sprite::init()) {
        return false;
    }
    auto background = LayerColor::create(Color4B(255, 0, 0, 0));
    background -> setContentSize(Size(55, 55));
    background -> setPosition(Vec2(0, 0));
    this -> addChild(background);
    this -> pos = pos;
    return true;
}

void Mino::setPos(Vec2 pos) {
    this -> pos = pos;
}

Vec2 Mino::getPos() {
    auto pos = Vec2(this -> pos);
    return pos;
}