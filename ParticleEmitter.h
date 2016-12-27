#pragma once
#include "Particle.h"
#include <SDL.h>

class ParticleEmitter
{

public:
	ParticleEmitter(SDL_Renderer *render, int x, int y);
	~ParticleEmitter();

	static const int TOTAL_PARTICLES = 20;

	int posX, posY;

	void render(SDL_Renderer *render);
	void loadEverything(SDL_Renderer *render);
	void resetPosition(int x, int y);

private:

	Particle *particles[TOTAL_PARTICLES];

};

