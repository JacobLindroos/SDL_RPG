#include "TextureManager.h"

//returning a texture from loading and rendering a picture
SDL_Texture* TextureManager::LoadTexture(const std::string& fileName)
{
	SDL_Surface* tempSurface = IMG_Load(fileName.c_str());
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst)
{
	SDL_RenderCopy(Game::renderer, tex, &src, &dst);
}
