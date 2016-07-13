//
//  Tetrimino_I.cpp
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#include "Tetrimino_I.hpp"

USING_NS_CC;

Tetrimino_I *Tetrimino_I::cerate() {
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
    return true;
}

std::array<Vec2, 4> Tetrimino_I::isRotateable() {
//    返回旋转后的位置
    std::array<Vec2, 4> a;
    return a;
}