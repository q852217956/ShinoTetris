//
//  GameLayer.cpp
//  HelloCpp
//
//  Created by shino on 16/7/16.
//
//

#include "GameLayer.hpp"
#include "ControlButton.hpp"

#include "Mino.hpp"

USING_NS_CC;

bool GameLayer::init() {
    if (!Layer::init()) {
        return false;
    }
    // 添加背景
    auto background = LayerColor::create(Color4B(255, 0, 0, 0));
    this -> addChild(background);

    //添加游戏区域
    auto gameArea = LayerColor::create(Color4B(255, 255, 255, 255));
    gameArea -> setContentSize(Size(600, 960));
    gameArea -> setPosition(Vec2(60, 100));
    this -> addChild(gameArea);

    auto leftControlButton = ControlButton::create(DIRECTION::LEFT);
    auto rightControlButton = ControlButton::create(DIRECTION::RIGHT);
    this -> addChild(leftControlButton);
    this -> addChild(rightControlButton);

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener -> onTouchBegan = [=](Touch *touch, Event *event) {
        auto touchArea = Rect(gameArea -> getPosition(), gameArea -> getContentSize());
        if (touchArea.containsPoint(touch -> getLocation())) {
            istouching = true;
            this -> schedule([=](float dt){
                if (istouching) {
                    this -> control(DIRECTION::DOWN);
                } else {
                    this -> control(DIRECTION::ROTATE);
                }
            }, 0.5, kRepeatForever, 0.5, "OnTouching");
            return true;
        } else {

            return false;
        }
    };
    touchListener -> onTouchEnded = [=](Touch *touch, Event *event){
        istouching = false;
        this -> unschedule("OnTouching");
    };

    this -> scheduleOnce([=](float dt){
        this -> movingTetrimino = Tetrimino::create();
        this -> nextTetrimono = Tetrimino::create();
    }, 0.5, "TetriminoInit");

//    this -> schedule([=](float dt){
//        this -> control(DIRECTION::DOWN);
//    }, 0.8, kRepeatForever, 0.8, "TetriminoDown");

    auto moveEventListener = EventListenerCustom::create("MoveEvent", [=](EventCustom *event){
        this -> movingTetrimino -> move();
    });

    auto downEventListener = EventListenerCustom::create("DownEvent", [=](EventCustom *event){
        this -> movingTetrimino -> move();
    });

    auto downOverEventListener = EventListenerCustom::create("DownOver", [=](EventCustom *event){
        this -> movingTetrimino = this -> nextTetrimono;
        this -> nextTetrimono = Tetrimino::create();
    });

    auto eventDispatcher = Director::getInstance() -> getEventDispatcher();
    eventDispatcher -> addEventListenerWithSceneGraphPriority(touchListener, this);
    eventDispatcher -> addEventListenerWithFixedPriority(moveEventListener, 2);
    eventDispatcher -> addEventListenerWithFixedPriority(downEventListener, 2);
    eventDispatcher -> addEventListenerWithFixedPriority(downOverEventListener, 2);

    return true;
}

void GameLayer::control(DIRECTION direction) {
    this -> movingTetrimino -> isMoveable(direction);
}
