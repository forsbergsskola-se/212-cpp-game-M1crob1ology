#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "RenderWindow.h"
#include "GameObject.h"

using namespace std;

RenderWindow::RenderWindow(const char* title, int width, int height) : success{}
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		return;
	}

	//Initialize SDL Image
	if (!(IMG_Init(IMG_INIT_PNG)))
		cout << "IMG_Init could not initialize! SDL_Error: " << SDL_GetError << endl;

	//Create window
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (!window)
	{
		cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	//Get window surface
	screenSurface = SDL_GetWindowSurface(window);
	success = true;
}

unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> RenderWindow::loadTexture(const char* filePath)
{
	SDL_Texture* texture{};
	texture = IMG_LoadTexture(renderer, filePath);

	if (!texture)
		cout << "Failed to load texture. Error: " << SDL_GetError() << endl;
	return std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>(texture, SDL_DestroyTexture);
}

RenderWindow::~RenderWindow()
{
	//Destroy window
	SDL_DestroyWindow(window);
	window = nullptr;

	//Quit SDL subsystems
	SDL_Quit();
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}


void RenderWindow::render(GameObject& p_gameObject) 
{
	SDL_Rect src;
	src.x = p_gameObject.getCurrentFrame().x;
	src.y = p_gameObject.getCurrentFrame().y;
	src.w = p_gameObject.getCurrentFrame().w;
	src.h = p_gameObject.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = p_gameObject.pos.x;
	dst.y = p_gameObject.pos.y;
	dst.w = p_gameObject.getCurrentFrame().w * p_gameObject.getScale().x;
	dst.h = p_gameObject.getCurrentFrame().h * p_gameObject.getScale().y;

	SDL_RenderCopy(renderer, &p_gameObject.getTex().getTexture(), &src, &dst);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}

// For making animation for the player later
// const int numberOfSprites = 5;
// int currentSprite = 3;
// src.w = p_gameObject.getCurrentFrame().w/numberOfSprites;
// src.h = p_gameObject.getCurrentFrame().h;
// src.x = p_gameObject.getCurrentFrame().x+currentSprite*src.w;
// src.y = p_gameObject.getCurrentFrame().y;