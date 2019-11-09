#pragma once

#include <SDL.h>

class Collision
{
public:
	//function that checks for collision, return true/false if there..
	//..is a collision
	static bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB);

};