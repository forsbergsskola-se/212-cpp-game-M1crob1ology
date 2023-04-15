#include "DeadState.h"

#include "MenuState.h"

// Start
DeadState::DeadState(std::unique_ptr<std::vector<std::unique_ptr<GameObject>>> p_world, RenderWindow p_window) :
world{std::move(p_world)},
window{p_window}
{
    
}

void MenuState::handleInput(SDL_Event input)
{
    if(/* space */)
    {
        restartGame = true;
        
    }
}

// Update
std::unique_ptr<GameState> DeadState::update()
{
    if(/* space */)
    {
        return std::make_unique<MenuState>(window);
    }
}