#pragma once

#include <memory>
#include <vector>
#include "../Utils/GameState.h"
#include "../Utils/Math.h"
#include "../Utils/RenderWindow.h"

extern class GameObject;

class MenuState : public GameState
{
public:
    MenuState(RenderWindow p_window);
    GameState* update(SDL_Event input) override;
    std::unique_ptr<std::vector<std::unique_ptr<GameObject>>> world;
    RenderWindow window;
};
