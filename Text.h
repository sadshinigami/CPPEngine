#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "Game.h"

class Text
{
public:

	TTF_Font *font = NULL;

	bool needToRenderText;

	bool initText(char *fontLocation, int fontSize);
	bool loadText(SDL_Renderer *render, Uint8 red, Uint8 green, Uint8 blue, const char* text);
	
	void renderText(SDL_Renderer *render, int x, int y);

	int getWidth();
	int getHeight();

	void destroyText();

	std::string returnTextInput();
	void handleEvent(SDL_Event &ev);
	void startTextInput();
	void stopTextInput();
	void handleRenderNeeds(SDL_Renderer *render);

private:

	SDL_Texture *tTexture;

	int tWidth;
	int tHeight;

	std::string textInput = "Type here";

};

