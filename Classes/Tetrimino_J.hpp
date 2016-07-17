//
//  Tetrimino_J.hpp
//  HelloCpp
//
//  Created by shino on 16/7/16.
//
//

#ifndef Tetrimino_J_hpp
#define Tetrimino_J_hpp

#include "Tetrimino.hpp"

class Tetrimino_J: public Tetrimino {
public:
    static Tetrimino_J *create();
    bool init();

    void isMoveable(DIRECTION);
    virtual std::array<cocos2d::Vec2, 4> isRotateable();
};

#endif /* Tetrimino_J_hpp */
