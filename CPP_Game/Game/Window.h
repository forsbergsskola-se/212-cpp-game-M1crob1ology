#pragma once
#include <SDL.h> // This is not how Marc did it in the loom but I had to add it for it to work for some reason...

#include "Image.h"

class Window
{
	//The window we'll be rendering to
	SDL_Window* window{};
	//The surface contained by the window
	SDL_Surface* screenSurface{};
	//Whether Window startup was successful
	bool success;

	

public:
	Window(int width, int height);
	~Window();
	bool wasSuccessful() { return success; }
	void render(Image* image) const;

};

