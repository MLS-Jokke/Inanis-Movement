#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include"W_Window.h"
#include"P_Character.h"

class G_Character {

private:
	int chHeight, chWidth;
	SDL_Texture* _chTexture;
	W_Window* p_Window;
	P_Character* p_Character;
public:
private:
public:
	G_Character(P_Character* p_Character, W_Window* p_Window, std::string charFilePath);
	void renderCharacter();
	bool loadFromFile(std::string filePath);
	void free();
	int getChWidth() { return chWidth; }
	int getChHeight() { return chHeight; }

};