//
//  ControlButton.hpp
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#ifndef ControlButton_hpp
#define ControlButton_hpp

#include "cocos2d.h"
#include "Direction.h"
#include "ControlButtonDelegate.h"

class ControlButton: public cocos2d::Sprite {
public:
    static ControlButton* create(DIRECTION);
    bool init(DIRECTION);

    void setDelegator(ControlButtonDelegate*);
private:
    DIRECTION direction;
    ControlButtonDelegate *delegator;
    void touchInit();
};

#endif /* ControlButton_hpp */
