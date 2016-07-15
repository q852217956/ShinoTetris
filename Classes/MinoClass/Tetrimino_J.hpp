//
//  Tetrimino_J.hpp
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#ifndef Tetrimino_J_hpp
#define Tetrimino_J_hpp

#include "Tetrimino.hpp"

class Tetrimino_J : public Tetrimino {
public:
	static Tetrimino_J *create();
	bool init();
	virtual std::array<cocos2d::Vec2, 4> isRotateable();
};

#endif /* Tetrimino_J_hpp */
