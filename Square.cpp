#include "Square.h"

Square::Square(){

	posX = 0;
	posY = 0;

	sHitbox.x = posX;
	sHitbox.y = posY;
	sHitbox.w = SQUARE_WIDTH;
	sHitbox.h = SQUARE_HEIGHT;

	velX = 0;
	velY = 0;

}

int Square::getPosX() {

	return posX;

}

int Square::getPosY() {

	return posY;
}

void Square::handleEvent(SDL_Event &ev) {

	if (ev.type == SDL_KEYDOWN && ev.key.repeat == 0) {

		switch (ev.key.keysym.sym) {

		case SDLK_UP:
			velY -= SQUARE_VEL;
			break;
		case SDLK_LEFT:
			velX -= SQUARE_VEL;
			break;
		case SDLK_RIGHT:
			velX += SQUARE_VEL;
			break;
		case SDLK_DOWN:
			velY += SQUARE_VEL;
			break;
		}
	}
	else if (ev.type == SDL_KEYUP && ev.key.repeat == 0) {

		switch (ev.key.keysym.sym) {

		case SDLK_UP:
			velY += SQUARE_VEL;
			break;
		case SDLK_LEFT:
			velX += SQUARE_VEL;
			break;
		case SDLK_RIGHT:
			velX -= SQUARE_VEL;
			break;
		case SDLK_DOWN:
			velY -= SQUARE_VEL;
			break;
		}
	}
}
void Square::move() {

	posX += velX;
	sHitbox.x = posX;

	if ((posX < 0) || (posX + SQUARE_WIDTH > Game::LEVEL_WIDTH)){

		posX -= velX;
		sHitbox.x = posX;

	}

	posY += velY;
	sHitbox.y = posY;

	if ((posY < 0) || (posY + SQUARE_HEIGHT > Game::LEVEL_HEIGHT)) {

		posY -= velY;
		sHitbox.y = posY;

	}

}

void Square::render(Image &img, SDL_Renderer* render,int camX, int camY) {

	img.renderTexture(render, posX - camX, posY - camY);

}
