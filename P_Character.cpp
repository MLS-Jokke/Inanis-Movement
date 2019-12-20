#include"P_Character.h"
#include<iostream>

P_Character::P_Character() {
	backwardDashVelocity = -screenWidth/4;
	forwardDashVelocity = screenWidth/13;
	standardVelocity = screenWidth/50;
	jumpVelocity = screenHeight/7;
	fallVelocity = screenHeight/20;
	
}

void P_Character::setChHeight(int height) {
	if (height < 0) {
		return;
	}
	chHeight = height;
}

void P_Character::setChWidth(int width) {
	if (width < 0) {
		return;
	}
	chWidth = width;
	charXPos = screenWidth / 2 - chWidth / 2;
}

void P_Character::setCharX(int posX) {
	if (posX > screenWidth - chWidth || posX < 0) return;
	charXPos = posX;
}

void P_Character::setCharY(int posY) {
	charYPos = posY;
}

void P_Character::updateCharacter(int moveDirection) {
	if (charYPos < BOTTOM) setCharY(charYPos + fallVelocity);
	switch (moveDirection) {
	case LEFT_MOVE:
		setCharX(charXPos - standardVelocity);
		break;
	case RIGHT_MOVE:
		setCharX(charXPos + standardVelocity);
		break;
	case LEFT_DASH:
		setCharX(charXPos + backwardDashVelocity);
		break;
	case RIGHT_DASH:
		setCharX(charXPos + forwardDashVelocity);
		break;
	case DIAG_LEFT:
		setCharX(charXPos - standardVelocity);
		if (charYPos < chHeight - 150) return;
		setCharY(charYPos - jumpVelocity);
		break;
	case DIAG_RIGHT:
		setCharX(charXPos + standardVelocity);
		if (charYPos < chHeight - 150) return;
		setCharY(charYPos - jumpVelocity);
		break;
	case JUMP:
		if (charYPos < chHeight -150) return;
		setCharY(charYPos - jumpVelocity);
		break;
	default: 
		if (charXPos == (screenWidth / 2) - chWidth / 2) return;
		else if (charXPos > (screenWidth / 2) - chWidth/2) setCharX(charXPos - standardVelocity);
	} 

}



