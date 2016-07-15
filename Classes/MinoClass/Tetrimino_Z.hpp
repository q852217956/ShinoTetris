//
//  Tetrimino_Z.hpp
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#ifndef Tetrimino_Z_hpp
#define Tetrimino_Z_hpp

#include "Tetrimino.hpp"

class Tetrimino_Z : public Tetrimino {
public:
	static Tetrimino_Z *create();
	bool init();
	virtual std::array<cocos2d::Vec2, 4> isRotateable();
};

#endif /* Tetrimino_Z_hpp */
