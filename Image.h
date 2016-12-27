#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

class Image
{
public:
	Image();
	~Image();

	bool loadTexture(char* path, bool ColorKey, Uint8 RED, Uint8 GREEN, Uint8 BLUE, SDL_Renderer *renderer);

	void setColor(Uint8 RED, Uint8 GREEN, Uint8 BLUE);
	void setBlenderMode(SDL_BlendMode blend);
	void setAlpha(Uint8 alpha);

	void renderTexture(SDL_Renderer *renderer, int x, int y, SDL_Rect *clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void destroyTexture();

	int getWidth();
	int getHeight();


private:

	SDL_Texture *mTexture;
	int mWidth;
	int mHeight;

};

