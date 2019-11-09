#pragma once

#include <iostream>
#include <SDL.h>
#include "Components.h"
class ColliderComponent : public Component
{
public:
	//represent an area that is colliedable
	SDL_Rect collider;
	//when we detecte a collision we can grab the tag of the object we collided with..
	//..and the make updates depending on what we collided with
	std::string tag;

	TransformComponent* transform;

	ColliderComponent(std::string t)
	{
		tag = t;
	}

	void init() override
	{
		//error check if we have a transform component or not..
		//..if not we create one otherwise we set transform to the entitys transform component
		if (!entity->hasComponent<TransformComponent>())
		{
			entity->addComponent<TransformComponent>();
		}

		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override
	{
		collider.x = static_cast<int>(transform->position.x);
		collider.y = static_cast<int>(transform->position.y);
		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale;
	}

};