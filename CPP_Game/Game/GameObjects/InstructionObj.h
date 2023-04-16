#pragma once
#include "../Utils/GameObject.h"
#include "../Utils/RenderWindow.h"

class InstructionObj : public GameObject
{
public:
    InstructionObj(Vector2f p_pos, Vector2f p_scale, std::shared_ptr<Image> p_tex);
    void update() override;
};
