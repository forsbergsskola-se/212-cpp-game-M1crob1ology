#pragma once

#include "SDL.h"

class GameState
{
public:
    virtual GameState* update(SDL_Event input) = 0;
};
