#pragma once
#include <random>
#include "Player.h"
#include "../Utils/GameObject.h"
#include "../Utils/RenderWindow.h"

class ObstacleObj : public GameObject
{
    std::shared_ptr<Player> player;
    int randomOffset{};
    std::mt19937 rng; // Mersenne Twister random number generator
    std::uniform_int_distribution<int> dist{-300, 300};
public:
    ObstacleObj(Vector2f p_pos, Vector2f p_scale, std::shared_ptr<Image> p_tex/*, std::shared_ptr<Player> p_player*/);
    void update() override;
    
};
