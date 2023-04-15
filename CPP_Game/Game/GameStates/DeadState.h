#pragma once

#include <vector>

#include "../Utils/GameState.h"
#include "../Utils/RenderWindow.h"

class DeadState : public GameState
{
public:
    DeadState(std::unique_ptr<std::vector<std::unique_ptr<GameObject>>> p_world, RenderWindow p_window);
    GameState* update(SDL_Event input) override;
    std::unique_ptr<std::vector<std::unique_ptr<GameObject>>> world;
    RenderWindow window;
};
