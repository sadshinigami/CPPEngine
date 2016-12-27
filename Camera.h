#pragma once
#include <SDL.h>
#include "Image.h"
#include "Game.h"
#include "Square.h" 

class Camera
{
public:
	Camera();

	void renderCamera();
	void centerCamera(Square square);

	int returnScrollOffset();

	SDL_Rect returnRect();

private:

	int scrollOffset;
	SDL_Rect camera;

};

