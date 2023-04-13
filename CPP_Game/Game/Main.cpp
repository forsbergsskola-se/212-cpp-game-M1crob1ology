#include <cstdio>
#include <map>
#include <SDL.h>
#include <SDL_image.h>
#include <memory>
#include <vector>
#include "Image.h"
#include "RenderWindow.h"
#include "GameObject.h"
#include "Math.h"
#include "Utils.h"


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
const char* fallbackSurface{ "img/press.bmp" };

int main(int argc, char* args[])
{
	RenderWindow window("Da game", SCREEN_WIDTH, SCREEN_HEIGHT);

	SDL_Texture* groundTexture = window.loadTexture("img/pngs/ground_2.png");
	SDL_Texture* zdTexture = window.loadTexture("img/pngs/zombie_dinosaur_idle.png");


	std::vector<GameObject> gameObjects =
	{
		GameObject(Vector2f(0,0),zdTexture),
		GameObject(Vector2f(0,30),groundTexture),
		GameObject(Vector2f(30,30),groundTexture),
	};

	//Start up SDL and create window
	if (!window.wasSuccessful())
	{
		printf("Failed to initialize!\n");
		return -1;
	}

	bool gameRunning{ true };
	SDL_Event event;
	const float timeStep{ 0.01f };
	float accumulator{ 0.0f };
	float currentTime{ utils::hireTimeInSeconds() };

	// Game Loop
	while (gameRunning)
	{
		int startTicks = SDL_GetTicks();

		float newTime = utils::hireTimeInSeconds();
		float frameTime = newTime - currentTime;

		currentTime = newTime;
		accumulator += frameTime;

		while(accumulator >= timeStep)
		{
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
					gameRunning = false;
			}

			accumulator -= timeStep;
		}

		const float alpha = accumulator / timeStep;

		window.clear();

		for (auto& gameObject : gameObjects)
		{
			gameObject.render(&window);
		}

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