#pragma once
#include <iostream>
#include <SDL_mixer.h>

class Audio
{
public:
	Audio();
	~Audio();

	Mix_Music *aMusic = NULL;
	Mix_Chunk *aChunk = NULL;

	bool loadAudio (char *fileLocation);
	bool loadMusic (char *fileLocation);

	///<summary>
	///For infinite loops, or play the music until you want to pause it, loops = -1
	///</summary>
	void playMusic(int loop);
	void playAudio(int loop);

	void pauseMusic();
	void resumeMusic();
	void stopMusic();

	void freeAudio(bool isMusic);

};

