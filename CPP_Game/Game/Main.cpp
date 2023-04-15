#include <cstdio>
#include <map>
#include <SDL.h>
#include <SDL_image.h>
#include <memory>
#include <vector>
#include "Utils/Image.h"
#include "Utils/RenderWindow.h"
#include "Utils/GameObject.h"
#include "GameObjects/GroundObj.h"
#include "GameObjects/Player.h"
#include "GameStates/DeadState.h"
#include "Utils/Math.h"
#include "Utils/Utils.h"
#include "GameStates/MenuState.h"
#include "GameStates/RunningState.h"


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
const char* fallbackSurface{"img/press.bmp"};

int main(int argc, char* args[])
{
    RenderWindow window("Da game", SCREEN_WIDTH, SCREEN_HEIGHT);
    //Start up SDL and create window
    if (!window.wasSuccessful())
    {
        printf("Failed to initialize!\n");
        return -1;
    }

    bool gameRunning{true};
    SDL_Event event;
    bool quit = false;
    const float timeStep{0.01f};
    float accumulator{0.0f};
    float currentTime{utils::hireTimeInSeconds()};

    bool moveLeft = false;
    bool moveRight = false;

    // Game Loop
    while (gameRunning)
    {
        std::unique_ptr<GameState> currentState = std::make_unique<MenuState>(window);

        int startTicks = SDL_GetTicks();

        float newTime = utils::hireTimeInSeconds();
        float frameTime = newTime - currentTime;

        currentTime = newTime;
        accumulator += frameTime;

        while (accumulator >= timeStep)
        {
            while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                case SDL_QUIT:
                    {
                        quit = true;
                    }
                    break;
                case SDL_KEYDOWN:
                    {
                        if (event.key.keysym.sym == SDLK_LEFT)
                        {
                            moveLeft = true;
                        }
                        else if (event.key.keysym.sym == SDLK_RIGHT)
                        {
                            moveRight = true;
                        }
                    }
                    break;
                case SDL_KEYUP:
                    {
                        if (event.key.keysym.sym == SDLK_LEFT)
                        {
                            moveLeft = false;
                        }
                        else if (event.key.keysym.sym == SDLK_RIGHT)
                        {
                            moveRight = false;
                        }
                    }
                    break;
                }
                if (event.type == SDL_QUIT) quit = true;
                currentState->handleInput(event);
            }

            // Do shit here
            auto newState = currentState->update();
            if (newState != nullptr)
            {
                currentState = std::move(newState);
            }

            accumulator -= timeStep;
        }

        const float alpha = accumulator / timeStep;

        // Rendering happens in the states
        window.clear();
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
