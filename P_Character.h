#pragma once
//#include"P_CharChars.h"
#include"G_Background.h"
#define LEFT_MOVE 1
#define RIGHT_MOVE 2
#define LEFT_DASH 3
#define RIGHT_DASH 4
#define JUMP 5
#define FALL 6
#define DIAG_LEFT 7
#define DIAG_RIGHT 8
#define BOTTOM 350

class P_Character {
private:
	int backwardDashVelocity; // = Chars::backwardDash;
	int forwardDashVelocity; //= Chars::forwardDash;
	int standardVelocity; //= Chars::moveVelocity;
	int jumpVelocity; //= Chars::jumpVelocity;
	int fallVelocity; //= Chars::fallVelocity;
	int charXPos;
	int charYPos = BOTTOM;
	int chHeight, chWidth;

public:

private:
	
public:
	void setChWidth(int width);
	void setChHeight(int height);
	void updateCharacter(int moveDirection);
	P_Character();
	void setCharX(int posX);
	void setCharY(int posY);
	int getCharX() { return charXPos; }
	int getCharY() { return charYPos; }
	int getForwardDashVelocity() { return forwardDashVelocity; }
	int getStandardVelocity() { return standardVelocity; }
	int getBackwardDashVelocity() { return backwardDashVelocity; }
	int getJumpVelocity() { return jumpVelocity; }
	int getFallVelocity() { return fallVelocity; }


};
