//
//  Tetrimino_O.hpp
//  HelloCpp
//
//  Created by shino on 16/7/16.
//
//

#ifndef Tetrimino_O_hpp
#define Tetrimino_O_hpp

#include "Tetrimino.hpp"

class Tetrimino_O: public Tetrimino {
public:
    static Tetrimino_O *create();
    bool init();

    void isMoveable(DIRECTION);
    virtual std::array<cocos2d::Vec2, 4> isRotateable();
};

#endif /* Tetrimino_O_hpp */
