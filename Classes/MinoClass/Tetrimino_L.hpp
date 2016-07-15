//
//  Tetrimino_L.hpp
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#ifndef Tetrimino_L_hpp
#define Tetrimino_L_hpp

#include "Tetrimino.hpp"

class Tetrimino_L : public Tetrimino {
public:
	static Tetrimino_L *create();
	bool init();
	virtual std::array<cocos2d::Vec2, 4> isRotateable();
};

#endif /* Tetrimino_L_hpp */
