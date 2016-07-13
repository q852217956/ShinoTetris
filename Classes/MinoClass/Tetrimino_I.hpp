//
//  Tetrimino_I.hpp
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#ifndef Tetrimino_I_hpp
#define Tetrimino_I_hpp

#include "Tetrimino.hpp"

class Tetrimino_I: public Tetrimino {
public:
    static Tetrimino_I *cerate();
    bool init();
    virtual std::array<cocos2d::Vec2, 4> isRotateable();
};

#endif /* Tetrimino_I_hpp */
