#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS.h"
#include "Components.h"
#include "Vector2D.h"
#include "Collision.h"

Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());

Game::Game()
{
	//initializing member variabels
	isRunning = true;
	window = nullptr;
	renderer = nullptr;
	playerTexture = nullptr;
}

Game::~Game()
{
}


//Initializing the game
void Game::Init(const std::string& title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	//if we want fullscreen or not, change the flags value to either 1 or 0
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem Initialized.." << std::endl;

		//creating a window
		window = SDL_CreateWindow(title.c_str(), xpos, ypos, width, height, flags);
		//if the window wasn´t created we throw an error
		if (!window)
		{
			std::cout << "SDL_Window error: " << SDL_GetError() << std::endl;
		}
		else //..otherwise we print a message that say´s it was created
		{
			std::cout << "Window created!" << std::endl;
		}

		//creating a renderer for our window
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		//if the renderer wasn´t created we throw an error
		if (!renderer)
		{
			std::cout << "SDL_Renderer error: " << SDL_GetError() << std::endl;
		}
		else //..otherwise we print a message that say´s it was created
		{
			//setting the backgrounndcolor to white
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;

		map = new Map();

		player.addComponent<TransformComponent>(2);
		player.addComponent<SpriteComponent>("Assets/Pictures/Dude.png");
		player.addComponent<KeyboardController>();
		player.addComponent<ColliderComponent>("dude");

		wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
		wall.addComponent<SpriteComponent>("Assets/WorldSprite/Dirt.png");
		wall.addComponent<ColliderComponent>("wall");

	}
	else
	{
		std::cout << "SDL_Init error: " << SDL_GetError() << std::endl;
		isRunning = false;
	}
}


//handle input events from the user using a switch-statement
void Game::HandleEvents()
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT: //if we click the "X" in the window toprightcorner we close down the app
		isRunning = false;
		break;
	default:
		//std::cout << "Unhandled event!" << std::endl;
		break;
	}
}


void Game::Update()
{
	manager.refresh();
	manager.update();

	if (Collision::AABB(player.getComponent<ColliderComponent>().collider,
		wall.getComponent<ColliderComponent>().collider))
	{
		player.getComponent<TransformComponent>().scale = 1;
		std::cout << "Wall hit!" << std::endl;
	}
}


void Game::Render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	manager.draw();
	SDL_RenderPresent(renderer);
}


//cleaning up the memory before shuting down
void Game::CleanUp()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned.." << std::endl;
}
