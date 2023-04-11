#include <cstdio>
#include <map>
#include <SDL.h>
#include <SDL_image.h>
#include <memory>
#include "Image.h"
#include "RenderWindow.h"
#include "GameObject.h"


const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

enum class KeyPressSurfaces
{
	Default,
	Up,
	Down,
	Left,
	Right,
	Total
};


const std::map<SDL_KeyCode, const char*> surfaceMap
{
	{SDL_KeyCode::SDLK_UP, "img/up.bmp"},
	{SDL_KeyCode::SDLK_DOWN, "img/down.bmp"},
	{SDL_KeyCode::SDLK_LEFT, "img/left.bmp"},
	{SDL_KeyCode::SDLK_RIGHT, "img/right.bmp"}

};
const char* fallbackSurface{"img/press.bmp" };

int main(int argc, char* args[])
{
	RenderWindow window("Da game", SCREEN_WIDTH, SCREEN_HEIGHT);

	SDL_Texture* groundTexture = window.loadTexture("img/pngs/ground_2.png");

	GameObject groundObject(100, 50, groundTexture);

	//Start up SDL and create window
	if (!window.wasSuccessful())
	{
		printf("Failed to initialize!\n");
		return -1;
	}

	bool gameRunning{true};
	SDL_Event event;
	while (gameRunning)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}

		window.clear();
		window.render(groundObject);
		window.display();
	}

	// Old stuff
	////Load media
	//auto image = std::make_unique<Image>( fallbackSurface );
	//if (!image->wasSuccessful())
	//{
	//	printf("Failed to load media!\n");
	//	return -1;
	//}

	////Hack to get window to stay up
	//SDL_Event e;
	//bool quit = false;
	//while (quit == false)
	//{
	//	while (SDL_PollEvent(&e))
	//	{
	//		switch (e.type)
	//		{
	//			case SDL_QUIT:
	//			{
	//				quit = true;
	//			} break;
	//			case SDL_KEYDOWN:
	//			{
	//				if(auto result = surfaceMap.find((SDL_KeyCode)e.key.keysym.sym); result != surfaceMap.end())
	//				{
	//					auto value = *result;
	//					auto imageName = value.second;
	//					image = std::make_unique<Image>( imageName );
	//				}
	//				else
	//				{
	//					image = std::make_unique<Image>(fallbackSurface);
	//				}
	//			}break;
	//		}
	//		if (e.type == SDL_QUIT) quit = true;
	//	}
	//	window.render(image.get());
	//}

	//return 0;
}