#pragma once

#include <memory>
#include <vector>
#include "../Utils/GameState.h"
#include "../Utils/RenderWindow.h"

class GameObject;

class RunningState : public GameState
{
public:
    RunningState(std::unique_ptr<std::vector<std::unique_ptr<GameObject>>> p_world, RenderWindow& p_window);
    RunningState();
    bool dead{};
    std::unique_ptr<GameState> fixedUpdate() override;
    void handleInput(SDL_Event input) override;
    // std::unique_ptr<std::vector<std::unique_ptr<GameObject>>> world;
    RenderWindow& window;
};
