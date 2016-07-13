//
//  Mino.hpp
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#ifndef Mino_hpp
#define Mino_hpp

#include "cocos2d.h"

//    这个目前不用改
class Mino: public cocos2d::Sprite {
public:
    static Mino *create(cocos2d::Vec2);
    bool init(cocos2d::Vec2);

    void setPos(cocos2d::Vec2);
    cocos2d::Vec2 getPos();
    bool onRow(int);
    
private:
    cocos2d::Vec2 pos;
};

#endif /* Mino_hpp */
