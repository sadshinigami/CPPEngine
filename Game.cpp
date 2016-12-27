#include "Game.h"

Game::Game(){

	gWindow = NULL;
	renderer = NULL;
	gScreenSurface = NULL;

	wMouseFocus = false;
	wKeyboardFocus = false;
	wFullscreen = false;
	wMinimized = false;

	wWidth = 0;
	wHeight = 0;

}

bool Game::initEngine(char *windowName) {

	bool initSucess = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {

		printf("A Engine não foi iniciada pelo seguinte erro: \n %s \n", SDL_GetError());
		initSucess = false;
		return initSucess;
	}
	else {

		gWindow = SDL_CreateWindow(windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		renderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		if (gWindow == NULL) {

			printf("A janela não pode ser criada pelo seguinte erro: \n %s \n", SDL_GetError());
			initSucess = false;
			return initSucess;

		}
		else {

			gScreenSurface = SDL_GetWindowSurface(gWindow);
			wMouseFocus = true;
			wKeyboardFocus = true;
			wWidth = SCREEN_WIDTH;
			wHeight = SCREEN_HEIGHT;

		}

	}

	if (TTF_Init() == -1) {

		printf("SDL_TTF não foi iniciado!\nERRO: %s", TTF_GetError());
		initSucess = false;

	}

	if (Mix_OpenAudio(48000, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {

		printf("Falha ao iniciar SDL_Mixer!\nERRO:%s\n", Mix_GetError());
		initSucess = false;

	}

	return initSucess;

}

void Game::handleEvents(SDL_Event &ev) {

	bool updateCaption = false;

	switch (ev.type) {

	case SDL_WINDOWEVENT:

		switch (ev.window.event) {

		case SDL_WINDOWEVENT_SIZE_CHANGED:
			wWidth = ev.window.data1;
			wHeight = ev.window.data2;
			SDL_RenderPresent(renderer);
			break;

		case SDL_WINDOWEVENT_EXPOSED:
			SDL_RenderPresent(renderer);
			break;

		case SDL_WINDOWEVENT_ENTER:
			wMouseFocus = true;
			updateCaption = true;
			break;

		case SDL_WINDOWEVENT_LEAVE:
			wMouseFocus = false;
			updateCaption = true;
			break;
		case SDL_WINDOWEVENT_FOCUS_GAINED:
			wKeyboardFocus = true;
			updateCaption = true;
			break;
		case SDL_WINDOWEVENT_FOCUS_LOST:
			wKeyboardFocus = false;
			updateCaption = true;
			break;

		case SDL_WINDOWEVENT_MINIMIZED:
			wMinimized = true;
			break;

		case SDL_WINDOWEVENT_MAXIMIZED:
			wMinimized = false;
			break;

		case SDL_WINDOWEVENT_RESTORED:
			wMinimized = false;
			break;

		}

		if (updateCaption) {

			//std::stringstream caption;
			//caption << "SDL Tutorial - MouseFocus:" << ((wMouseFocus) ? "On" : "Off") << " KeyboardFocus:" << ((wKeyboardFocus) ? "On" : "Off");
			//std::cout << caption.str() << std::endl;

		}

		break;

	case SDL_KEYDOWN:

		if (ev.key.keysym.sym == SDLK_RETURN) {

			if (wFullscreen) {

				SDL_SetWindowFullscreen(gWindow, SDL_FALSE);
				wFullscreen = false;

			}
			else {

				SDL_SetWindowFullscreen(gWindow, SDL_TRUE);
				wFullscreen = true;
				wMinimized = false;

			}

		}
		break;

	}

}

int Game::getWindowWidth() {

	return wWidth;

}

int Game::getWindowHeight() {

	return wHeight;

}

bool Game::hasMouseFocus() {

	return wMouseFocus;

}

bool Game::hasKeyboardFocus() {

	return wKeyboardFocus;

}

bool Game::isMinimized() {

	return wMinimized;

}

void Game::freeSurface(SDL_Surface *surfaceName) {

	SDL_FreeSurface(surfaceName);
	surfaceName = NULL;

}

void Game::freeTexture(SDL_Texture *textureName) {

	SDL_DestroyTexture(textureName);
	textureName = NULL;

}

void Game::destroyRenderer() {

	SDL_DestroyRenderer(renderer);
	renderer = NULL;

}

void Game::destroyWindow() {

	SDL_DestroyWindow(gWindow); 
	gWindow = NULL;

}
