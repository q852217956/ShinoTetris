//
//  ControlButton.hpp
//  HelloCpp
//
//  Created by shino on 16/7/16.
//
//

#ifndef ControlButton_hpp
#define ControlButton_hpp

#include "cocos2d.h"
#include "ControlButtonDelegate.h"

class ControlButton: public cocos2d::Sprite {
public:
    static ControlButton *create(DIRECTION);
    bool init(DIRECTION);

    void setDelegator(ControlButtonDelegate*);

private:
    DIRECTION direction;
    ControlButtonDelegate *delegator;
};

#endif /* ControlButton_hpp */
