#pragma once
#include <SDL.h>
#include "Image.h"
#include "Game.h"

class Square
{

public:

	Square();

	int posX, posY;
	int velX, velY;
	SDL_Rect sHitbox;

	static const int SQUARE_WIDTH = 20;
	static const int SQUARE_HEIGHT = 20;
	static const int SQUARE_VEL = 10;

	void handleEvent(SDL_Event &ev);

	int getPosX();
	int getPosY();

	void move();
	void render(Image &img, SDL_Renderer *render, int camX, int camY);

};

