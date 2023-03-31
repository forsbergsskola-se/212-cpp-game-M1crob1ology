#include <cstdio>
#include <SDL.h>
#include "Window.h"

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();



//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;



bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	gHelloWorld = SDL_LoadBMP("img/hello_world.bmp");
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "img/hello_world.bmp", SDL_GetError());
		success = false;
	}

	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main(int argc, char* args[])
{
	Window window(SCREEN_WIDTH, SCREEN_HEIGHT);

	//Start up SDL and create window
	if (!window.wasSuccessful())
	{
		printf("Failed to initialize!\n");
		return -1;
	}

	//Load media
	if (!loadMedia())
	{
		printf("Failed to load media!\n");
	}
	else
	{
		//Apply the image
		SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
		//Update the surface
		SDL_UpdateWindowSurface(gWindow);
		//Hack to get window to stay up
		SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
	}


	//Free resources and close SDL
	close();

	return 0;
}