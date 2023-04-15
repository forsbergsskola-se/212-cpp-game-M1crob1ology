#include "DeadState.h"

#include "MenuState.h"

// Start
DeadState::DeadState(std::unique_ptr<std::vector<std::unique_ptr<GameObject>>> p_world, RenderWindow p_window) :
world{std::move(p_world)},
window{p_window}
{
    
}

// Update
GameState* DeadState::update(SDL_Event input)
{
    if(/* space */)
    {
        return new MenuState(window);
    }
}