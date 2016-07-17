//
//  Tetrimino_Z.hpp
//  HelloCpp
//
//  Created by shino on 16/7/16.
//
//

#ifndef Tetrimino_Z_hpp
#define Tetrimino_Z_hpp

#include "Tetrimino.hpp"

class Tetrimino_Z: public Tetrimino {
public:
    static Tetrimino_Z *create();
    bool init();

    void isMoveable(DIRECTION);
    virtual std::array<cocos2d::Vec2, 4> isRotateable();
};

#endif /* Tetrimino_Z_hpp */
