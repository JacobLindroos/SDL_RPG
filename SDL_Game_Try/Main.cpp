#include <iostream>
#include <SDL.h>

#include "Game.h"

Game* game = nullptr;


int main(int argc, char* argv[])
{
	//closest to screen update rate
	const int FPS = 60;
	//maxtime between frames
	const int FrameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->Init("Jacob's Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while (game->Running())
	{
		//get the current running time in milliseconds
		frameStart = SDL_GetTicks();

		game->HandleEvents();
		game->Update();
		game->Render();

		//current time in milliseconds minus milliseconds since start
		frameTime = SDL_GetTicks() - frameStart;
		//delaying the update with the difference between frameDelay and frameTime
		if (FrameDelay > frameTime)
		{
			SDL_Delay(FrameDelay - frameTime);
		}
	}
	game->CleanUp();

	return 0;
}