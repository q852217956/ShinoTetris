//
//  GameLayer.hpp
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#ifndef GameLayer_hpp
#define GameLayer_hpp

#include "cocos2d.h"
#include "ControlButtonDelegate.h"
#include "Tetrimino.hpp"

class GameLayer: public cocos2d::Sprite, ControlButtonDelegate {
public:
    virtual bool init();
    CREATE_FUNC(GameLayer);

    virtual void control(DIRECTION);

private:
    void touchInit();
    bool isTouching;
    void tetriminoDown(float);

    Tetrimino *movingTetrimino;
    Tetrimino *nextTetrimino;
};

#endif /* GameLayer_hpp */
