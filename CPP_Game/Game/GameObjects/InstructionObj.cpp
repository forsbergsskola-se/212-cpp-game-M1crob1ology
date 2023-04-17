#include "InstructionObj.h"

InstructionObj::InstructionObj(Vector2f p_pos, Vector2f p_scale, std::shared_ptr<Image> p_tex)
    : GameObject(p_pos, p_scale, p_tex)
{
    // any additional initialization for the ground object
    // can be done here
}

void InstructionObj::update()
{
    // Moves ground to the left and teleports them to the right when off screen
    if (!(pos.x <= -SCREEN_WIDTH / 2))
    {
        pos.x -= 3;
    }
    
}
