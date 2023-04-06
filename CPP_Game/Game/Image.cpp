#include "Image.h"
#include <SDL.h>
#include <cstdio>
#include <iostream>
#include <SDL_image.h>

using namespace std;

Image::Image(const char* path) : success{}
{
	//Load splash image
	imageSurface = SDL_LoadBMP(path);
	if (!imageSurface)
	{
		cout << "Unable to load image " << path << "! SDL Error:" << SDL_GetError() << endl;
		return;
	}

	success = true;
}

Image::~Image()
{
	//Deallocate surface
	//SDL_FreeSurface(imageSurface);
	//imageSurface = nullptr;
}
