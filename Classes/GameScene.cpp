//
//  GameScene.cpp
//  HelloCpp
//
//  Created by shino on 16/7/16.
//
//

#include "GameScene.hpp"
#include "GameLayer.hpp"

USING_NS_CC;

bool GameScene::init() {
    if (!Scene::init()) {
        return false;
    }
    auto rootLayer = GameLayer::create();
    this -> addChild(rootLayer, 1, "RootLayer");
    return true;
}