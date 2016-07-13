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

class Tetrimino_I: public cocos2d::Ref {
public:
    static Tetrimino_I *cerate();
    bool init();
    virtual void isRotateable();
};

#endif /* Tetrimino_I_hpp */
