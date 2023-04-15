#pragma once
#include "GameObject.h"
#include "RenderWindow.h"

class GroundObj : public GameObject
{
public:
    GroundObj(Vector2f p_pos, Vector2f p_scale, std::shared_ptr<Image> p_tex);
    void update() override;
    
};
