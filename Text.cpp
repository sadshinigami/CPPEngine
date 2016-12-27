#include "Text.h"

bool Text::initText(char *fontLocation, int fontSize) {

	bool initFontSucess = true;

	font = TTF_OpenFont(fontLocation, fontSize);
	if (font == NULL) {
		printf("Falha ao iniciar fonte '%s'!\n ERRO: %s", fontLocation,TTF_GetError());
		initFontSucess = false;
	}

	return initFontSucess;
}

bool Text::loadText(SDL_Renderer *render, Uint8 red, Uint8 green, Uint8 blue, const char* text) {
	
	destroyText();

	SDL_Color textColor{ red, green, blue };
	SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, textColor);
	if (textSurface == NULL)
		printf("Nao foi possivel carregar a fonte, por causa do seguinte erro: \n %s \n", TTF_GetError());
	else {

		tTexture = SDL_CreateTextureFromSurface(render, textSurface);
		if (tTexture == NULL)
			printf("Nao foi possivel criar a textura, por causa do seguinte erro: \n %s \n", SDL_GetError());
		else {

			tWidth = textSurface->w;
			tHeight = textSurface->h;

		}
	}

	SDL_FreeSurface(textSurface);

	return tTexture != NULL;
}

void Text::renderText(SDL_Renderer *render, int x, int y) {

	SDL_Rect textPos{ x, y, tWidth, tHeight };
	SDL_RenderCopy(render, tTexture, NULL, &textPos);

}

int Text::getWidth() {

	return tWidth;

}

int Text::getHeight() {

	return tHeight;

}

void Text::destroyText() {

	if (tTexture != NULL) {

		SDL_DestroyTexture(tTexture);
		tTexture = NULL;
		tWidth = 0;
		tHeight = 0;

	}

}

std::string Text::returnTextInput() {

	return textInput;

}

void Text::handleEvent(SDL_Event  &ev) {

	needToRenderText = false;

	switch (ev.type) {

	case SDL_KEYDOWN:

		if (ev.key.keysym.sym == SDLK_BACKSPACE && textInput.length() > 0) {

			textInput.pop_back();
			needToRenderText = true;

		}
		else if (ev.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL) {

			SDL_SetClipboardText(textInput.c_str());

		}
		else if (ev.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL) {

			textInput += SDL_GetClipboardText();
			needToRenderText = true;

		}

		break;

	case SDL_TEXTINPUT:

		if (!((ev.text.text[0] == 'c' || ev.text.text[0] == 'C') && (ev.text.text[0] == 'v' || ev.text.text[0] == 'V') && SDL_GetModState() & KMOD_CTRL)) {

			textInput += ev.text.text;
			needToRenderText = true;

		}

		break;

	}

}

void Text::startTextInput() {

	SDL_StartTextInput();

}

void Text::stopTextInput() {

	SDL_StopTextInput();

}

void Text::handleRenderNeeds(SDL_Renderer *render) {

	if (needToRenderText) {

		if (returnTextInput() != "") {
			
			loadText(render, 255, 255, 255, returnTextInput().c_str());
			
		}
		else {
			loadText(render, 255, 255, 255, "");
		}

	}
	

}