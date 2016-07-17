//
//  Tetrimino.hpp
//  HelloCpp
//
//  Created by shino on 16/7/16.
//
//

#ifndef Tetrimino_hpp
#define Tetrimino_hpp

#include "cocos2d.h"
#include <array>
#include "DirectionEnum.h"
#include "Mino.hpp"

class Tetrimino: public cocos2d::Ref {
public:
    static Tetrimino *create();

    void isMoveable(DIRECTION);
    virtual std::array<cocos2d::Vec2, 4> isRotateable() = 0;
    void move();

    std::array<cocos2d::Vec2, 4> posToMove;
    std::array<cocos2d::Vec2, 4> realPosToMove;
    std::array<cocos2d::Vec2, 4> rotate[4];

    int rotateType;
    int totalRotateType;

    Mino *mino[4];
};

#endif /* Tetrimino_hpp */
