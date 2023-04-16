#include "RunningState.h"

#include "DeadState.h"
#include "../GameObjects/GroundObj.h"
#include "../GameObjects/Player.h"

class GroundObj;

// Start
RunningState::RunningState(std::unique_ptr<std::vector<std::unique_ptr<GameObject>>> p_world, RenderWindow& p_window) :
GameState{std::move(p_world)},
window{p_window}
{
    dead = false;
}

// temporary bool


void RunningState::handleInput(SDL_Event input)
{
    for (auto& gameObject : *world)
    {
        gameObject->handleInput(input);
    }
    if (input.type == SDL_KEYDOWN)
    {
        if(input.key.keysym.sym == SDLK_BACKSPACE && !dead)
        {
            dead = true;
        }
    }
}

// Update
std::unique_ptr<GameState> RunningState::update()
{
    std::cout << "running\n";
    if(true == dead)
    {
        return std::make_unique<DeadState>(std::move(world), window);
    }

    // Move world and stuff
    for (auto& object : *world)
    {
        object->update();
    }

    return nullptr;
}