#pragma once

#include "GameObject.h"
#include "RenderWindow.h"
#include "SDL.h"


class GameState
{
public:
    GameState(std::unique_ptr<std::vector<std::unique_ptr<GameObject>>> world) : world{std::move(world)} {};
    std::unique_ptr<std::vector<std::unique_ptr<GameObject>>> world;
    virtual void handleInput(SDL_Event input){}
    virtual std::unique_ptr<GameState> update() = 0;
    virtual void render(RenderWindow& window)
    {
        for (auto &object : *world)
        {
            window.render(*object);
        }
        
    };
};
