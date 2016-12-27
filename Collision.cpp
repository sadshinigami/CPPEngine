#include "Collision.h"

Collision::Collision()
{
}


bool Collision::squareCollision(SDL_Rect rectA, SDL_Rect rectB) {

	int topA, topB;
	int downA, downB;
	int leftA, leftB;
	int rightA, rightB;

	topA = rectA.y;
	topB = rectB.y;
	
	downA = rectA.h + rectA.y;
	downB = rectB.h + rectB.y;

	leftA = rectA.x;
	leftB = rectB.x;

	rightA = rectA.x + rectA.w;
	rightB = rectB.x + rectB.w;


	if (downA <= topB){ 
		return false; 
	}

	if (topA >= downB){ 
		return false; 
	}

	if (rightA <= leftB){ 
		return false; 
	}

	if (leftA >= rightB){ 
		return false; 
	}

	return true;
}

bool Collision::roundCollision() {

	return false;

}
