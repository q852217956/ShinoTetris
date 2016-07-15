//
//  Tetrimino_S.hpp
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#ifndef Tetrimino_S_hpp
#define Tetrimino_S_hpp

#include "Tetrimino.hpp"

class Tetrimino_S : public Tetrimino {
public:
	static Tetrimino_S *create();
	bool init();
	virtual std::array<cocos2d::Vec2, 4> isRotateable();
};

#endif /* Tetrimino_S_hpp */
