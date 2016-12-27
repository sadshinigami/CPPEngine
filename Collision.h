#pragma once
#include <SDL.h>
#include "Square.h"

class Collision
{
public:
	Collision();
	
	bool squareCollision(SDL_Rect rectA, SDL_Rect rectB);
	bool roundCollision();

};

