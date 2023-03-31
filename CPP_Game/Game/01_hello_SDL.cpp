#include <cstdio>
#include <SDL.h>
#include "Image.h"
#include "Window.h"


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


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
	Image image{ "img/hello_world.bmp" };
	if (!image.wasSuccessful())
	{
		printf("Failed to load media!\n");
		return -1;
	}

	window.render(image);

	
	//Hack to get window to stay up
	SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }

	return 0;
}