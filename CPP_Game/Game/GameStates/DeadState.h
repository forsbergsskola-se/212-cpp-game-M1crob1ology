#pragma once

#include <vector>

#include "../Utils/GameState.h"
#include "../Utils/RenderWindow.h"

class DeadState : public GameState
{
    bool restartGame{};
public:
    DeadState(std::unique_ptr<std::vector<std::unique_ptr<GameObject>>> p_world, RenderWindow& p_window);
    std::unique_ptr<GameState> update() override;
    void handleInput(SDL_Event input) override;
    //std::unique_ptr<std::vector<std::unique_ptr<GameObject>>> world;
    RenderWindow window;
};
