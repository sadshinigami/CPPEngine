#include "Audio.h"

Audio::Audio()
{
}


Audio::~Audio()
{
}

bool Audio::loadAudio(char *fileLocation) {

	bool loadAudioSucess = true;

	aChunk = Mix_LoadWAV(fileLocation);
	if (aChunk == NULL) {

		printf("Falha ao iniciar: %s\n Erro%s\n", fileLocation, Mix_GetError());
		loadAudioSucess = false;

	}
		
	return loadAudioSucess;
}

bool Audio::loadMusic(char *fileLocation) {

	bool loadMusicSucess = true;

	aMusic = Mix_LoadMUS(fileLocation);
	if (aMusic == NULL) {

		printf("Falha ao iniciar: %s\n Erro%s\n", fileLocation, Mix_GetError());
		loadMusicSucess = false;

	}

	return loadMusicSucess;

}

void Audio::playAudio(int loop) {

	Mix_PlayChannel(-1, aChunk, loop);

}

void Audio::playMusic(int loop)
{
	Mix_PlayMusic(aMusic, loop);
}

void Audio::pauseMusic() {

	Mix_PauseMusic();

}

void Audio::resumeMusic() {

	Mix_ResumeMusic();

}

void Audio::stopMusic() {

	Mix_HaltMusic();

}

void Audio::freeAudio(bool isMusic) {

	if (isMusic) {

		Mix_FreeMusic(aMusic);
		aMusic = NULL;

	}
	else {

		Mix_FreeChunk(aChunk);
		aChunk = NULL;

	}

}
