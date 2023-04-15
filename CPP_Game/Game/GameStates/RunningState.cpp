#include "RunningState.h"

#include "DeadState.h"

// Start
RunningState::RunningState(std::unique_ptr<std::vector<std::unique_ptr<GameObject>>> p_world, RenderWindow p_window) :
world{std::move(p_world)},
window{p_window}
{
    
}

// Update
GameState* RunningState::update(SDL_Event input)
{
    if(/* dead */)
    {
        return new DeadState(window);
    }
}