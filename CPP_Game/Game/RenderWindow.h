#pragma once
#include <SDL.h> // This is not how Marc did it in the loom but I had to add it for it to work for some reason...
#include  <SDL_image.h>
#include "Image.h"
#include "GameObject.h"

class RenderWindow
{
	//The window we'll be rendering to
	SDL_Window* window{};

	SDL_Renderer* renderer{};
	//The surface contained by the window
	SDL_Surface* screenSurface{};
	//Whether Window startup was successful
	bool success;

	

public:
	RenderWindow(const char* title, int width, int height);
	~RenderWindow();
	std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> loadTexture(const char* filePath);
	bool wasSuccessful() { return success; }
	void clear();
	void render(GameObject& p_gameObject);
	void display();

};

