//
//  GameLayer.cpp
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#include "GameLayer.hpp"

USING_NS_CC;

bool GameLayer::init() {
    if (!GameLayer::init()) {
        return false;
    }
    auto background = LayerColor::create(Color4B(255, 0, 0, 0));
    this -> addChild(background);

    auto gameArea = LayerColor::create(Color4B(255, 255, 255, 255));
    gameArea -> setContentSize(Size(600, 960));
    gameArea -> setPosition(Vec2(60, 100));
    this -> addChild(gameArea);
//    this -> movingTetrimino = Tetrimino::create();
//    this -> nextTetrimino = Tetrimino::create();
    return true;
}

void GameLayer::touchInit() {
    auto touchEventListener = EventListenerTouchOneByOne::create();
    touchEventListener -> onTouchBegan = [&](Touch *touch, Event *event){
        auto touchArea = Rect(60, 100, 600, 960);
        if (touchArea.containsPoint(touch -> getLocation())) {
            this -> isTouching = true;
            this -> scheduleOnce([=](float dt){
//                if (this -> isTouching) {
//                    this -> movingTetrimino -> move(DIRECTION::DOWN);
//                } else {
//                    this -> movingTetrimino -> move(DIRECTION::ROTATE);
//                }
            }, 0.25, "IsFloatOrDown");
            return true;
        } else {
            return false;
        }
    };
    touchEventListener -> onTouchEnded = [=](Touch *touch, Event *event){
        this -> isTouching = false;
    };
}

void GameLayer::tetriminoDown(float dt) {
    
}

void GameLayer::control(DIRECTION direction) {
//    this -> movingTetrimino -> move(direction);
    this -> movingTetrimino -> isMoveable(DIRECTION::DOWN);
}