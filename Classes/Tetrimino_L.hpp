//
//  Tetrimino_L.hpp
//  HelloCpp
//
//  Created by shino on 16/7/16.
//
//

#ifndef Tetrimino_L_hpp
#define Tetrimino_L_hpp

#include "Tetrimino.hpp"

class Tetrimino_L: public Tetrimino {
public:
    static Tetrimino_L *create();
    bool init();

    void isMoveable(DIRECTION);
    virtual std::array<cocos2d::Vec2, 4> isRotateable();
};

#endif /* Tetrimino_L_hpp */
