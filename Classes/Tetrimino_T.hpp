//
//  Tetrimino_T.hpp
//  HelloCpp
//
//  Created by shino on 16/7/16.
//
//

#ifndef Tetrimino_T_hpp
#define Tetrimino_T_hpp

#include "Tetrimino.hpp"

class Tetrimino_T: public Tetrimino {
public:
    static Tetrimino_T *create();
    bool init();

    void isMoveable(DIRECTION);
    virtual std::array<cocos2d::Vec2, 4> isRotateable();
};

#endif /* Tetrimino_T_hpp */
