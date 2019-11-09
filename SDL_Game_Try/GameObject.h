#pragma once

#include "Game.h"

class GameObject
{
public:
	GameObject(const std::string& textureSheet, int x, int y);
	~GameObject();

	//update each new gameObject within it´s self instead in the update in Game.cpp
	void Update();
	void Render();

private:

	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, dstRect;

};

