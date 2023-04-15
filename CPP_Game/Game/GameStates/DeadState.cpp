#include "DeadState.h"
#include "MenuState.h"

// Start
DeadState::DeadState(std::unique_ptr<std::vector<std::unique_ptr<GameObject>>> p_world, RenderWindow& p_window) :
GameState{std::move(p_world)},
window{std::move(p_window)}
{
    
}

void DeadState::handleInput(SDL_Event input)
{
    if(input.key.keysym.sym == SDLK_SPACE)
    {
        restartGame = true;
        
    }
}

// Update
std::unique_ptr<GameState> DeadState::update()
{
    if(restartGame)
    {
        return std::make_unique<MenuState>(window);
    }
    return nullptr;
}