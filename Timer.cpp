#include "Timer.h"

Timer::Timer(){

	runningTime = 0;
	pausedTime = 0;

	isPaused = false;
	hasStarted = false;

}

void Timer::start() {

	hasStarted = true;
	isPaused = false;

	runningTime = SDL_GetTicks();
	pausedTime = 0;

}

void Timer::stop() {

	hasStarted = false;
	isPaused = false;

	runningTime = 0;
	pausedTime = 0;

}

void Timer::pause() {

	if (hasStarted && !isPaused) {

		isPaused = true;

		pausedTime = SDL_GetTicks() - runningTime;
		runningTime = 0;

	}

}

void Timer::unpause() {

	if (hasStarted && isPaused) {

		isPaused = false;

		runningTime = SDL_GetTicks() - pausedTime;
		pausedTime = 0;

	}

}

Uint32 Timer::getTicks() {

	Uint32 time = 0;
	
	if (hasStarted) {

		if (isPaused) {

			time = pausedTime;
		}
		else {

			time = SDL_GetTicks() - runningTime;

		}
	}

	return time;
}

bool Timer::isRunning() {

	return hasStarted;

}

bool Timer::paused() {

	return isPaused && hasStarted;

}
