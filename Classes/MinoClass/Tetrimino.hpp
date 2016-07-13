//
//  Tetrimino.hpp
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#ifndef Tetrimino_hpp
#define Tetrimino_hpp

enum class TETRIMINO_TYPE {
    I,
    J,
    L,
    O,
    S,
    Z,
    T
};

#include "cocos2d.h"
#include "Direction.h"
#include "Mino.hpp"
#include <array>

class Tetrimino: public cocos2d::Ref {
public:
    static Tetrimino *create();

    void isMoveable(DIRECTION);
    bool move(DIRECTION);
    std::array<cocos2d::Vec2, 4> posToMove;

protected:
    Mino *mino[4];
    std::array<cocos2d::Vec2, 4> pos;
    virtual std::array<cocos2d::Vec2, 4> isRotateable() = 0;

};

#endif /* Tetrimino_hpp */
