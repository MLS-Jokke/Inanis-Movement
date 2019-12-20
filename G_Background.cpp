#include"G_Background.h"
#include <SDL_image.h>


G_Background::G_Background(W_Window* p_Window, std::string filePath) : p_Window(p_Window){
	loadFromFile(filePath);
}

G_Background::~G_Background() {
	free();
}

void G_Background::free() {
	if (_bgTexture != nullptr) {
		SDL_DestroyTexture(_bgTexture);
		_bgTexture = nullptr;
		bgWidth = 0;
		bgHeight = 0;
	}
}

void G_Background::setBackgroundMoveSpeed(int backgroundMoveSpeed) {
	movementSpeed = backgroundMoveSpeed;
}

bool G_Background::loadFromFile(std::string filePath) {
	free();

	SDL_Texture* tempTexture = nullptr;
	SDL_Surface* tempSurface = IMG_Load(filePath.c_str());

	if (!tempSurface) {
		std::cout << std::endl << "Error loading background surface! SDL Error: " << SDL_GetError();
	}

	else {
		tempTexture = SDL_CreateTextureFromSurface(p_Window->getRend(), tempSurface);
		if (!tempTexture) {
			std::cout << std::endl << "Error creating texture from surface! SDL Error: " << SDL_GetError();
		}
		else {
			bgWidth = tempSurface->w;
			bgHeight = tempSurface->h;
		}
		SDL_FreeSurface(tempSurface);
	}

	//Return success
	_bgTexture = tempTexture;
	return (_bgTexture != nullptr);
}

void G_Background::renderBackground(int x, int y) {
	SDL_Rect firstRect = { currentX, currentY, bgWidth - currentX, bgHeight };
	SDL_Rect secondRect = { 0, currentY, bgWidth, bgHeight };
	SDL_Rect backgroundRectLeft = { 0,0, firstRect.w, screenHeight };
	SDL_Rect backgroundRectRight = { bgWidth - currentX ,0 ,screenWidth, screenHeight };


	/*SDL_Rect firstRect = {currentX, currentY, bgWidth - currentX, bgHeight};
	SDL_Rect secondRect = {0, currentY, bgWidth, bgHeight};
	SDL_Rect backgroundRectLeft = {0,0, firstRect.w, screenHeight };
	SDL_Rect backgroundRectRight = {bgWidth - currentX ,0 ,screenWidth, screenHeight};
	*/

	currentX += movementSpeed;
	if (currentX > bgWidth) {
		currentX = 0;
	}
	//currentY += movementSpeed;
	//SDL_Rect renderQuad = { x, y, bgWidth, bgHeight };

	/*if (clip != nullptr)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}*/

	SDL_RenderCopy(p_Window->getRend(), _bgTexture, &firstRect, &backgroundRectLeft);
	SDL_RenderCopy(p_Window->getRend(), _bgTexture, &secondRect, &backgroundRectRight);
}

