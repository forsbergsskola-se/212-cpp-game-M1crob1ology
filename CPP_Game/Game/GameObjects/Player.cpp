#include "Player.h"

Player::Player(Vector2f p_pos, Vector2f p_scale, std::shared_ptr<Image> p_tex)
    : GameObject(p_pos, p_scale, p_tex)
{
    // any additional initialization for the player object
    // can be done here
}

void Player::Jump()
{
}

void Player::handleInput(SDL_Event& event)
{
    if(event.key.keysym.sym == SDLK_SPACE)
    {
        Jump();
    }
}
