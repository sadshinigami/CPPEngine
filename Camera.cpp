#include "Camera.h"

Camera::Camera(){

	scrollOffset = 0;
	camera.x = 0;
	camera.y = 0;
	camera.w = Game::SCREEN_WIDTH;
	camera.h = Game::SCREEN_HEIGHT;

}

void Camera::renderCamera() {

	if (camera.x < 0) {
		camera.x = 0;
	}
	if (camera.y < 0) {
		camera.y = 0;
	}
	if (camera.x > Game::LEVEL_WIDTH - camera.w) {
		camera.x = Game::LEVEL_WIDTH - camera.w;
	}
	if (camera.y > Game::LEVEL_HEIGHT - camera.h) {
		camera.y = Game::LEVEL_HEIGHT - camera.h;
	}

}

void Camera::centerCamera(Square square) {

	camera.x = (square.getPosX() + square.SQUARE_WIDTH / 2) - Game::SCREEN_WIDTH / 2;
	camera.y = (square.getPosY() + square.SQUARE_HEIGHT / 2) - Game::SCREEN_HEIGHT / 2;

}

int Camera::returnScrollOffset() {

	return scrollOffset;

} 

SDL_Rect Camera::returnRect() {

	return camera;

}