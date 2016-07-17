//
//  Mino.cpp
//  HelloCpp
//
//  Created by shino on 16/7/16.
//
//

#include "Mino.hpp"
#include <array>

USING_NS_CC;

Mino *Mino::create(Vec2 pos) {
    Mino *mino = new(std::nothrow) Mino();
    if (mino && mino -> init(pos)) {
        mino -> autorelease();
        return mino;
    } else {
        delete mino;
        mino = nullptr;
        return nullptr;
    }
}

bool Mino::init(Vec2 pos) {
    if (!Sprite::init()) {
        return false;
    }

    auto background = LayerColor::create(Color4B(255, 0, 0, 255));
    background -> setContentSize(Size(55, 55));
    this -> addChild(background);
    this -> pos = pos;
    this -> setPosition(this -> pos * 60 + Vec2(60, 100));

    Director::getInstance() -> getRunningScene() -> getChildByName("RootLayer") -> addChild(this);

    auto moveEventListener = EventListenerCustom::create("MoveEvent", [=](EventCustom *event){
        auto tetriminoPos = (std::array<Vec2, 4>*)(event -> getUserData());
        for (int i = 0; i < 4; i++) {
            if (this -> getPosition() == (*tetriminoPos)[i]) {
                event -> stopPropagation();
            }
        }
    });

    auto downEventListener = EventListenerCustom::create("DownEvent", [=](EventCustom *event){
        auto tetriminoPos = (std::array<Vec2, 4>*)(event -> getUserData());
        for (int i = 0; i < 4; i++) {
            if (this -> getPosition() == (*tetriminoPos)[i]) {
                event -> stopPropagation();
                auto downOverEvent = new EventCustom("DownOver");
                downOverEvent -> setUserData(event -> getUserData());
                Director::getInstance() -> getEventDispatcher() -> dispatchEvent(downOverEvent);
                delete downOverEvent;
            }
        }
    });

    auto downOverEventListener = EventListenerCustom::create("DownOver", [=](EventCustom *event){
        auto tetriminoPos = (std::array<Vec2, 4>*)(event -> getUserData());
        for (int i = 0; i < 4; i++) {
            if (this -> getPosition().x == (*tetriminoPos)[i].x) {
                this -> setNumOfSameRow();
            }
        }
    });

    auto eventDispatcher = Director::getInstance() -> getEventDispatcher();
    eventDispatcher -> addEventListenerWithFixedPriority(moveEventListener, 1);
    eventDispatcher -> addEventListenerWithFixedPriority(downEventListener, 1);
    eventDispatcher -> addEventListenerWithFixedPriority(downOverEventListener, 1);
    return true;
}

void Mino::setNumOfSameRow() {
    this -> numOfSameRow++;
    if (this -> numOfSameRow == 10) {
        auto lineClear = new EventCustom("LineClear");
        lineClear -> setUserData(&(this -> pos));
    }
}