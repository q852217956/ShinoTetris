//
//  GameScene.hpp
//  ShinoTetris
//
//  Created by shino on 16/7/11.
//
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include "cocos2d.h"

class GameScene: public cocos2d::Scene {
public:
    virtual bool init();
    CREATE_FUNC(GameScene);
};

#endif /* GameScene_hpp */
