//
//  Mino.hpp
//  HelloCpp
//
//  Created by shino on 16/7/16.
//
//

#ifndef Mino_hpp
#define Mino_hpp

#include "cocos2d.h"


class Mino: public cocos2d::Sprite {
public:
    static Mino *create(cocos2d::Vec2);
    bool init(cocos2d::Vec2);

    cocos2d::Vec2 pos;

    void setNumOfSameRow();

private:
    int numOfSameRow;
};

#endif /* Mino_hpp */
