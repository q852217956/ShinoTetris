//
//  Tetrimino_O.hpp
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#ifndef Tetrimino_O_hpp
#define Tetrimino_O_hpp

#include "Tetrimino.hpp"

class Tetrimino_O : public Tetrimino {
public:
	static Tetrimino_O *create();
	bool init();
	virtual std::array<cocos2d::Vec2, 4> isRotateable();
};

#endif /* Tetrimino_O_hpp */
