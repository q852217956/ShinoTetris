//
//  Tetrimino_T.hpp
//  ShinoTetris
//
//  Created by shino on 16/7/13.
//
//

#ifndef Tetrimino_T_hpp
#define Tetrimino_T_hpp

#include "Tetrimino.hpp"

class Tetrimino_T : public Tetrimino {
public:
	static Tetrimino_T *create();
	bool init();
	virtual std::array<cocos2d::Vec2, 4> isRotateable();
};

#endif /* Tetrimino_T_hpp */
