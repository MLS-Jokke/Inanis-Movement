#include"G_Character.h"

G_Character::G_Character(P_Character* p_Character, W_Window* p_Window, std::string charFilePath) : p_Character(p_Character), p_Window(p_Window) {
	loadFromFile(charFilePath);

}
void G_Character::renderCharacter() {
	SDL_Rect charRect = {0,0,chWidth, chHeight};
	SDL_Rect destRect = {p_Character->getCharX(), p_Character->getCharY(), chWidth, chWidth};
	SDL_RenderCopy(p_Window->getRend(), _chTexture, &charRect, &destRect);
}
bool G_Character::loadFromFile(std::string filePath) {
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
			chWidth = tempSurface->w;
			chHeight = tempSurface->h;
		}
		SDL_FreeSurface(tempSurface);
	}

	//Return success
	_chTexture = tempTexture;
	return (_chTexture != nullptr);
}
void G_Character::free() {
	if (_chTexture != nullptr) {
		SDL_DestroyTexture(_chTexture);
		_chTexture = nullptr;
		chWidth = 0;
		chHeight = 0;
	}
}