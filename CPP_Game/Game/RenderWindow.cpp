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

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	//Get window surface
	screenSurface = SDL_GetWindowSurface(window);
	success = true;
}

SDL_Texture* RenderWindow::loadTexture(const char* filePath)
{
	SDL_Texture* texture{};
	texture = IMG_LoadTexture(renderer, filePath);

	if (!texture)
		cout << "Failed to load texture. Error: " << SDL_GetError() << endl;
	return texture;
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
	dst.x = p_gameObject.getX() * 4;
	dst.y = p_gameObject.getY() * 4;
	dst.w = p_gameObject.getCurrentFrame().w * 4;
	dst.h = p_gameObject.getCurrentFrame().h * 4;

	SDL_RenderCopy(renderer, p_gameObject.getTex(), &src, &dst);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}


