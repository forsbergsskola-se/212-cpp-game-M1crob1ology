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

    SDL_Event event;
    bool quit = false;
    const float fixedTimeStep{0.01f};
    float timeNotSimulatedYet{0.0f};
    srand(time(NULL));
    float currentTime{utils::hireTimeInSeconds()};

        std::unique_ptr<GameState> currentState = std::make_unique<MenuState>(window);
    // Game Loop
    while (!quit)
    {

        float newTime = utils::hireTimeInSeconds();
        float timeSinceLastCheck = newTime - currentTime;
        currentTime = newTime;
        
        timeNotSimulatedYet += timeSinceLastCheck;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                {
                    quit = true;
                }
                break;
                    
            }
            currentState->handleInput(event);
        }
        
        while (timeNotSimulatedYet >= fixedTimeStep)
        {
            timeNotSimulatedYet -= fixedTimeStep;
            // Do shit here
            auto newState = currentState->fixedUpdate();
            if (newState != nullptr)
            {
                currentState = std::move(newState);
            }
        }

        const float alpha = timeNotSimulatedYet / fixedTimeStep;

        // Rendering happens in the states
        window.clear();
        currentState->render(window);
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
