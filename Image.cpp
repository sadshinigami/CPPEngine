#include "Image.h"

Image::Image(){

	if(mTexture != NULL)
		destroyTexture();

	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;

}


Image::~Image(){

	destroyTexture();

}

bool Image::loadTexture(char* path, bool ColorKey, Uint8 RED, Uint8 GREEN, Uint8 BLUE, SDL_Renderer *renderer) {

	destroyTexture();

	SDL_Texture *finalTexture = NULL;

	SDL_Surface *loadSurface = IMG_Load(path);
	if (loadSurface == NULL)
		printf("Nao foi possivel carregar a imagem %s,por causa do seguinte erro: \n %s \n", path, SDL_GetError());
	else {

		if (ColorKey)
			SDL_SetColorKey(loadSurface, SDL_TRUE, SDL_MapRGB(loadSurface->format, RED, GREEN, BLUE));

		finalTexture = SDL_CreateTextureFromSurface(renderer, loadSurface);
		if(finalTexture == NULL)
			printf("Nao foi possivel carregar a Textura %s,por causa do seguinte erro: \n %s \n", path, SDL_GetError());
		else {

			mWidth = loadSurface->w; 
			mHeight = loadSurface->h;

		}

		SDL_FreeSurface(loadSurface);

	}

	mTexture = finalTexture;
	return mTexture != NULL;

}

void Image::setColor(Uint8 RED, Uint8 GREEN, Uint8 BLUE) {

	SDL_SetTextureColorMod(mTexture, RED, GREEN, BLUE);

}

void Image::setBlenderMode(SDL_BlendMode blend) {

	SDL_SetTextureBlendMode(mTexture, blend);

}

void Image::setAlpha(Uint8 alpha) {

	SDL_SetTextureAlphaMod(mTexture, alpha);

}

void Image::renderTexture(SDL_Renderer *renderer, int x, int y, SDL_Rect *clip, double angle, SDL_Point *center, SDL_RendererFlip flip) {

	SDL_Rect renderPos{ x, y, mWidth, mHeight };
	SDL_RenderCopyEx(renderer, mTexture, clip, &renderPos, angle, center, flip);

}

int Image::getWidth() {

	return mWidth;

}

int Image::getHeight() {

	return mHeight;

}

void Image::destroyTexture() {

	if (mTexture != NULL) {

		SDL_DestroyTexture(mTexture); 
		mTexture = NULL; 
		mWidth = 0; 
		mHeight = 0;

	}

}