//
//  Tetrimino_I.hpp
//  HelloCpp
//
//  Created by shino on 16/7/16.
//
//

#ifndef Tetrimino_I_hpp
#define Tetrimino_I_hpp

#include "Tetrimino.hpp"

class Tetrimino_I: public Tetrimino {
public:
    static Tetrimino_I *create();
    bool init();

    void isMoveable(DIRECTION);
    virtual std::array<cocos2d::Vec2, 4> isRotateable();
};

#endif /* Tetrimino_I_hpp */
