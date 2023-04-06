#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "RenderWindow.h"

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

	RenderWindow::~RenderWindow()
	{
		//Destroy window
		SDL_DestroyWindow(window);
		window = nullptr;

		//Quit SDL subsystems
		SDL_Quit();
	}

	void RenderWindow::render(Image* image) const
	{
		//Apply the image
		SDL_BlitSurface(image->getResource(), nullptr, screenSurface, nullptr);
		//Update the surface
		SDL_UpdateWindowSurface(window);
	}
