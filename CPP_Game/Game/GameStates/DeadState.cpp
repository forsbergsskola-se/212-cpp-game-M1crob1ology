#include "DeadState.h"
#include "MenuState.h"
#include "../GameObjects/InstructionObj.h"

// Start
DeadState::DeadState(std::unique_ptr<std::vector<std::unique_ptr<GameObject>>> p_world, RenderWindow& p_window) :
GameState{std::move(p_world)},
window{p_window}
{
    auto restartInstruction = std::make_unique<InstructionObj>(Vector2f(SCREEN_WIDTH/3, 0), Vector2f(10,10), std::make_unique<Image>("img/pngs/restart.png",p_window));
    world->push_back(std::move(restartInstruction));
    //restartInstruction->render(&window);

}

void DeadState::handleInput(SDL_Event input)
{
    if (input.type == SDL_KEYDOWN)
    {
        if (input.key.keysym.sym == SDLK_SPACE && !restartGame)
        {
            restartGame = true;
        }
    }
}

// Update
std::unique_ptr<GameState> DeadState::fixedUpdate()
{
    std::cout << "dead\n";
    if(restartGame)
    {
        return std::make_unique<MenuState>(window);
    }
    return nullptr;
}