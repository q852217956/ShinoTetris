//
//  ControlButtonDelegate.h
//  HelloCpp
//
//  Created by shino on 16/7/16.
//
//

#ifndef ControlButtonDelegate_h
#define ControlButtonDelegate_h

#include "DirectionEnum.h"

class ControlButtonDelegate {
public:
    virtual ~ControlButtonDelegate() {}
    virtual void control(DIRECTION) = 0;
};

#endif /* ControlButtonDelegate_h */
