#pragma once
#include "Image.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Game
{

public:

	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;
	static const int LEVEL_WIDTH = 1920;
	static const int LEVEL_HEIGHT = 1080;
	static const int SCREEN_FPS = 60;
	static const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

	bool running;

	SDL_Event event;

	SDL_Window *gWindow;
	SDL_Renderer *renderer;
	SDL_Surface *gScreenSurface;

	Game();

	int getWindowWidth();
	int getWindowHeight();
	void handleEvents(SDL_Event &ev);

	bool hasMouseFocus();
	bool hasKeyboardFocus();
	bool isMinimized();

	bool initEngine(char *windowName);
	
	void freeSurface(SDL_Surface *surfaceName);
	void freeTexture(SDL_Texture *textureName);
	void destroyRenderer();
	void destroyWindow();

private:

	int wWidth;
	int wHeight;

	bool wMouseFocus;
	bool wKeyboardFocus;
	bool wFullscreen;
	bool wMinimized;

};

