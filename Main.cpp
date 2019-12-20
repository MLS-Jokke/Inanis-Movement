#include<iostream>
#include<SDL.h>
#include"G_Background.h"
#include"W_Window.h"
#include<SDL_image.h>
#include"E_PollEvents.h"
#include"P_Character.h"
#include"G_Character.h"

bool SDLSetup();

int main(int argc, char** args) {


	if (!SDLSetup()) {
		return 0;
	}

	W_Window Window("Background test ", screenWidth, screenHeight);
	G_Background background(&Window, "C:/Users/Marin/source/repos/MLS_Movement/background.png");
	P_Character character;
	G_Character G_Character(&character, &Window, "C:/Users/Marin/source/repos/MLS_Movement/character.png");
	character.setChHeight(G_Character.getChHeight());
	character.setChWidth(G_Character.getChWidth());
	E_PollEvents poll(&Window);

	SDL_SetRenderDrawColor(Window.getRend(), 0x00, 0x00, 0x00, 0xFF);
	std::cout << std::endl << "Setting window color!";
	
	int P_charAction = 0;

	while (!Window.getB_Closed()) {
		SDL_RenderClear(Window.getRend());

		
		SDL_Event event;
		SDL_SetRenderDrawColor(Window.getRend(), 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(Window.getRend());

		//Render background
		background.renderBackground(0, 0);

		//while (SDL_PollEvent(&event)) {
		SDL_PollEvent(&event);
			if (event.type == SDL_KEYDOWN) {
				const Uint8* keys = SDL_GetKeyboardState(NULL);
				if (keys[SDL_SCANCODE_LEFT] == SDL_PRESSED) P_charAction = (LEFT_MOVE);
				if (keys[SDL_SCANCODE_RIGHT] == SDL_PRESSED) P_charAction = (RIGHT_MOVE);
				if (keys[SDL_SCANCODE_UP] == SDL_PRESSED) {
					if (keys[SDL_SCANCODE_LEFT] == SDL_PRESSED) P_charAction = DIAG_LEFT;
					else if (keys[SDL_SCANCODE_RIGHT] == SDL_PRESSED) P_charAction = DIAG_RIGHT;
					else P_charAction = (JUMP);
				}
				if (keys[SDL_SCANCODE_LSHIFT] == SDL_PRESSED) {
					if (keys[SDL_SCANCODE_LEFT] == SDL_PRESSED) {
						P_charAction = (LEFT_DASH);
					}
					else if (keys[SDL_SCANCODE_RIGHT] == SDL_PRESSED) {
						P_charAction = (RIGHT_DASH);
					}
				}
			}
			character.updateCharacter(P_charAction);
			P_charAction = 0;

			/*switch (event.type) {
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_LEFT:
					character.updateCharacter(LEFT_MOVE);
					std::cout << std::endl << "Left nigga";
					break;
				case SDLK_RIGHT:
					character.updateCharacter(RIGHT_MOVE);
					std::cout << std::endl << "Right nigga";
					break;
				case SDLK_LSHIFT:
					{

						const Uint8*  keys = SDL_GetKeyboardState(NULL);
						if (keys[SDL_SCANCODE_LEFT] == SDL_PRESSED) {
							character.updateCharacter(LEFT_DASH);
						}
						else if (keys[SDL_SCANCODE_RIGHT] == SDL_PRESSED) {
							character.updateCharacter(RIGHT_DASH);
						}
					}
					break;
				default:
					break;
				}
				break;
			}*/
		//}


		/*int press = poll.globalEvents();
		std::cout << std::endl << "Pressed: " << press;
		if (press != 0) {
			character.updateCharacter(press);
		}*/
		G_Character.renderCharacter();
		//background.renderBackground(0 + background.getWidth(), 0);
		Window.draw();

	}


	SDL_Quit();

	return 0;
}

bool SDLSetup() {


	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "Failed to initialise SDL2_EVERYTHING!  SDL Error: " << SDL_GetError() << std::endl;
		return 0;
	}
	else {
		std::cout << "Sucessfully initialised SDL2 " << std::endl;

	}

	if (IMG_Init(IMG_INIT_PNG) < 0) {
		std::cout << "FAILED initialising SDL2_Image! SDL_Error: " << SDL_GetError() << std::endl;
		return 0;
	}
	else {
		std::cout << "Succesfull SDL2_Image init" << std::endl;
	}

	return 1;
}