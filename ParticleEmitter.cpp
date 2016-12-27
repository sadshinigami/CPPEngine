#include "ParticleEmitter.h"

ParticleEmitter::ParticleEmitter(SDL_Renderer *render, int x, int y){
	
	posX = x;
	posY = y;

	for (int i = 0; i < TOTAL_PARTICLES; ++i)
		particles[i] = new Particle{render, x, y};

}

void ParticleEmitter::render(SDL_Renderer *render) {

	for (int i = 0; i < TOTAL_PARTICLES; ++i) {

		if (particles[i]->isDead()) {

			delete particles[i];
			particles[i] = new Particle{ render, posX, posY };

		}

	}

	for (int i = 0; i < TOTAL_PARTICLES; ++i) {
		particles[i]->renderParticle(render);
	}

}

void ParticleEmitter::loadEverything(SDL_Renderer *render) {

	for (int i = 0; i < TOTAL_PARTICLES; ++i) {

		particles[i]->loadImages(render);

	}

}

void ParticleEmitter::resetPosition(int x, int y) {

	posX = x;
	posY = y;

}

ParticleEmitter::~ParticleEmitter(){

	for (int i = 0; i < TOTAL_PARTICLES; ++i)
		delete particles[i];

}
