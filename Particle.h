#pragma once
#include "Image.h"
#include <SDL.h>
#include <stdlib.h>

class Particle
{
public:

	Particle(SDL_Renderer *render, int x, int y);
	~Particle();

	static const int PARTICLE_WIDTH = 5;
	static const int PARTICLE_HEIGHT = 5;

	void renderParticle(SDL_Renderer *render);
	void loadImages(SDL_Renderer *render);
	bool isDead();

private:

	int posX, posY;
	
	int currentFrame;

	Image *particleImage;

	Image redParticle;
	Image greenParticle;
	Image blueParticle;
	Image shimmerParticle;

};

