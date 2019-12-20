#pragma once
#include<iostream>
#include<SDL.h>
#include"W_Window.h"

const int screenWidth = 1366;
const int screenHeight = 768;

class G_Background {
	
private:
	int bgHeight, bgWidth;
	SDL_Texture* _bgTexture;
	W_Window* p_Window;
	int movementSpeed = 5;
	int	currentX = 0;
	int	currentY = 0;
public:
private:
public:
	void renderBackground(int x, int y);
	void setBackgroundMoveSpeed(int backgroundMoveSpeed);
	int getBackgroundMoveSpeed(){ return movementSpeed; }
	G_Background(W_Window* p_Window, std::string filePath);
	~G_Background();
	bool loadFromFile(std::string filePath);
	void free();
	int getWidth() { return bgWidth; }
	int getHeight() { return bgHeight; }
};