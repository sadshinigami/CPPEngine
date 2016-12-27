#pragma once
#include <SDL.h>

class Timer
{
public:
	Timer();

	void start();
	void stop();
	void pause();
	void unpause();

	Uint32 getTicks();

	bool isRunning();
	bool paused();

private:

	Uint32 runningTime;
	Uint32 pausedTime;

	bool isPaused;
	bool hasStarted;

};

