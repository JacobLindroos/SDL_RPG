#pragma once

#include "Game.h"

class TextureManager
{
public:
	//returning a texture from loading and rendering a picture
	//static means there will only be one copy of this static function
	static SDL_Texture* LoadTexture(const std::string& fileName);

	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst);
};

