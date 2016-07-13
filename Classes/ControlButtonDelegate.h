//
//  ControlButtonDelegate.h
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#ifndef ControlButtonDelegate_h
#define ControlButtonDelegate_h

#include "Direction.h"

class ControlButtonDelegate {
public:
    virtual ~ControlButtonDelegate() {}
    virtual void control(DIRECTION) = 0;
};

#endif /* ControlButtonDelegate_h */
