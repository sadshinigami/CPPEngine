#include "Particle.h"

Particle::Particle(SDL_Renderer *render, int x, int y) {

	posX = x - PARTICLE_WIDTH + (rand() % 25);
	posY = y - PARTICLE_HEIGHT + (rand() % 25);

	currentFrame = rand() % 5;

	loadImages(render);

	switch (rand() % 3) {

	case 0:
		particleImage = &redParticle;
		break;
	case 1:
		particleImage = &blueParticle;
		break;
	case 2:
		particleImage = &greenParticle;
		break;

	}

}

void Particle::loadImages(SDL_Renderer *render) {

	redParticle.loadTexture("res/red.bmp", true, 0, 255, 255, render);
	greenParticle.loadTexture("res/green.bmp", true, 0, 255, 255, render);
	blueParticle.loadTexture("res/blue.bmp", true, 0, 255, 255, render);
	shimmerParticle.loadTexture("res/shimmer.bmp", true, 0, 255, 255, render);

	redParticle.setAlpha(192);
	greenParticle.setAlpha(192);
	blueParticle.setAlpha(192);
	shimmerParticle.setAlpha(192);

}

void Particle::renderParticle(SDL_Renderer *render) {

	particleImage->renderTexture(render, posX, posY);

	if (currentFrame % 2 == 0)
		shimmerParticle.renderTexture(render, posX, posY);

	currentFrame++;
}

bool Particle::isDead() {

	return currentFrame > 10;

}

Particle::~Particle() {

	

}