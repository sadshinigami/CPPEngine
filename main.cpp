#include <iostream>
#include <stdio.h>
#include <sstream>
#include <SDL.h>
#include "Game.h"
#include "Image.h"
#include "Text.h"
#include "Audio.h"
#include "Timer.h"
#include "Square.h"
#include "Collision.h"
#include "Camera.h"
#include "ParticleEmitter.h"

int main(int argc, char* args[]) {

	Game game;
	Camera camera;
	Image background;
	Image squareIMG;
	Square square;

	ParticleEmitter particleEmitter{ game.renderer, square.getPosX(), square.getPosY() };

	if (!game.initEngine("TESTE")) {
		printf("Falha ao iniciar! \n");
		return 0;
	}

	double degrees = 0;
	SDL_RendererFlip flipType = SDL_FLIP_NONE;

	background.loadTexture("res/background.png", false, 0, 0, 0, game.renderer);
	squareIMG.loadTexture("res/dot.bmp", true, 255, 255, 255, game.renderer);

	game.running = true;

	while (game.running) {

		while (SDL_PollEvent(&game.event) != 0) {

			switch (game.event.type) {

			case SDL_QUIT:

				game.running = false;

				game.freeSurface(game.gScreenSurface);
				background.destroyTexture();

				game.destroyRenderer();
				game.destroyWindow();
				
				SDL_Quit();

				break;
		
			}//Switch Event END

			game.handleEvents(game.event);
			square.handleEvent(game.event);

		} // PollEvent END

		square.move();

		//RENDER
		if (!game.isMinimized()) {
			SDL_SetRenderDrawColor(game.renderer, 0, 0, 0, 0);
			SDL_RenderClear(game.renderer);

			background.renderTexture(game.renderer, 0, 0, &camera.returnRect());

			particleEmitter.resetPosition(camera.returnRect().x, camera.returnRect().y);
			particleEmitter.render(game.renderer);

			square.render(squareIMG, game.renderer, camera.returnRect().x, camera.returnRect().y);
			camera.centerCamera(square);

			camera.renderCamera();

			SDL_RenderPresent(game.renderer);
		}
		
	}// game.running END

	return 0;
}