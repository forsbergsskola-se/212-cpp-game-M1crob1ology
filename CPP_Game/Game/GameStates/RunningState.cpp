#include "RunningState.h"

#include "DeadState.h"
#include "../GameObjects/GroundObj.h"

class GroundObj;

// Start
RunningState::RunningState(std::unique_ptr<std::vector<std::unique_ptr<GameObject>>> p_world, RenderWindow p_window) :
world{std::move(p_world)},
window{p_window}
{
    
}

void RunningState::handleInput(SDL_Event input)
{
    if(/* space */)
    {
        // jump
    }
}

// Update
std::unique_ptr<GameState> RunningState::update()
{
    if(/* dead */)
    {
        return std::make_unique<DeadState>(std::move(world), window);
    }

    // Move world and stuff
    for (GameObject object : world)
    {
        object.update();
    }

    return nullptr;
}