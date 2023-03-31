#pragma once
class Window
{
	//The window we'll be rendering to
	SDL_Window* gWindow{};
	//The surface contained by the window
	SDL_Surface* gScreenSurface{};
	bool init(int width, int height);
	//Whether Window startup was successful
	bool success;

public:
	Window(int width, int height)
	{
		init(width, height);
	}
	bool wasSuccessful() { return success; }
};

