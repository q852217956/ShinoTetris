//
//  ControlButton.cpp
//  HelloCpp
//
//  Created by shino on 16/7/16.
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
    this -> addChild(background);
    if (direction == DIRECTION::LEFT) {
        this -> setPosition(Vec2(60, 30));
    } else {
        this -> setPosition(Vec2(580, 30));
    }

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener -> onTouchBegan = [=](Touch *touch, Event *event){
        auto touchArea = Rect(background -> getPosition(), background -> getContentSize());
        if (touchArea.containsPoint(touch -> getLocation())) {
            this -> delegator -> control(this -> direction);
            return true;
        } else {
            return false;
        }
    };

    Director::getInstance() -> getEventDispatcher() -> addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}

void ControlButton::setDelegator(ControlButtonDelegate* delegator) {
    this -> delegator = delegator;
}