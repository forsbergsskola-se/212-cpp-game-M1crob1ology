#include "Player.h"

Player::Player(Vector2f p_pos, Vector2f p_scale, std::shared_ptr<Image> p_tex)
    : GameObject(p_pos, p_scale, p_tex), groundHeight{p_pos.y}
{
    // any additional initialization for the player object
    // can be done here
}



void Player::update()
{
    if (jump == 0)
        return;
    if (jump > jumpForce/2)  // Has not reached peak of jump
    {
        pos.y -= jumpSpeed;  // Go up fast in the beginning and slows down
    }
    else // On its way down
    {
        pos.y+= jumpSpeed;
    }

        --jump;
}


void Player::handleInput(SDL_Event& event)
{
    if(event.key.keysym.sym == SDLK_SPACE && !jump)
    {
        jump = jumpForce;
    }
}
