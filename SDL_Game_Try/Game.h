#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>

class Game
{
public:
	Game();
	~Game();

	void Init(const std::string& title, int xpos, int ypos, int width, int height, bool fullscreen);
	void HandleEvents();
	void Update();
	void Render();
	void CleanUp();
	bool Running()
	{ return isRunning; }

	static SDL_Renderer* renderer;
	static SDL_Event event;

private:

	int count{ 0 };
	bool isRunning;
	SDL_Window* window;
	SDL_Texture* playerTexture;
};

