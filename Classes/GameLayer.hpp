//
//  GameLayer.hpp
//  HelloCpp
//
//  Created by shino on 16/7/16.
//
//

#ifndef GameLayer_hpp
#define GameLayer_hpp

#include "cocos2d.h"
#include "ControlButtonDelegate.h"
#include "Tetrimino.hpp"

class GameLayer: public cocos2d::Layer, public ControlButtonDelegate {
public:
    virtual bool init();
    CREATE_FUNC(GameLayer);

    virtual void control(DIRECTION);

private:
    bool istouching;
    Tetrimino *movingTetrimino;
    Tetrimino *nextTetrimono;
};

#endif /* GameLayer_hpp */
