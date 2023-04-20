#include "ObstacleObj.h"

#include <cmath>

ObstacleObj::ObstacleObj(Vector2f p_pos, Vector2f p_scale, std::shared_ptr<Image> p_tex/*, std::shared_ptr<Player> p_player*/)
    : GameObject(p_pos, p_scale, p_tex)/*,player{p_player}*/
{
    std::random_device rd;
    rng.seed(rd());
}

void ObstacleObj::update()
{
    randomOffset = dist(rng);
    // Moves ground to the left and teleports them to the right when off screen
    if (pos.x <= -SCREEN_WIDTH / 2 + randomOffset)
    {
        pos.x += SCREEN_WIDTH + 2 * abs(randomOffset);
        randomOffset = dist(rng);
    }
    pos.x -= 3;

    // if (player->pos.y > 380 && player->pos.y <= 405) // Basically if the player is on the ground
    // {
    //     if (pos.x > 190 && pos.x < 210)
    //     {
    //         player->dead = true;
    //     }
    // }
}
