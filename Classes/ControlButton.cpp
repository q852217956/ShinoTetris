//
//  ControlButton.cpp
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#include "ControlButton.hpp"

USING_NS_CC;

ControlButton *ControlButton::create(DIRECTION direction) {
    ControlButton *controlButton = new(std::nothrow) ControlButton();
    if (controlButton && controlButton -> init(direction)) {
        controlButton -> autorelease();
        return controlButton;
    } else {
        delete controlButton;
        controlButton = nullptr;
        return nullptr;
    }
}

bool ControlButton::init(DIRECTION direction) {
    if (!Sprite::init()) {
        return false;
    }
    this -> direction = direction;
    auto background = LayerColor::create(Color4B(255, 255, 255, 255));
    background -> setContentSize(Size(80, 50));
    if (direction == DIRECTION::LEFT) {
        background -> setPosition(Vec2(60, 30));
    } else {
        background -> setPosition(Vec2(580, 30));
    }
    this -> addChild(background);

    this -> touchInit();
    
    return true;
}

void ControlButton::touchInit() {
    auto touchEventListener = EventListenerTouchOneByOne::create();
    touchEventListener -> onTouchBegan = [&](Touch *touch, Event *event){
        auto touchArea = Rect(this -> getPosition() - Vec2(80, 50) / 2, Size(80, 50));
        if (touchArea.containsPoint(touch -> getLocation())) {
            this -> delegator -> control(this -> direction);
            return true;
        } else {
            return false;
        }
    };
}