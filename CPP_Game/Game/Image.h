#pragma once
#include <SDL.h>
#include <memory>
#include <string>

class RenderWindow;

class Image
{
	//The image we will load and show on the screen
	std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> texture; 
	bool success;
public:
	int x, y, width, height;
	
	Image(const char* path, RenderWindow& window);
	std::unique_ptr<Image> loadImage(const char* path, const SDL_PixelFormat* pixelFormat);
	bool wasSuccessful() const { return success; }
	SDL_Texture& getTexture() const { return *texture; }
	Image& operator =(Image& other) = delete;
	Image& operator =(Image&& other) = default;
};

