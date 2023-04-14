#pragma once
#include "GameObject.h"
#include "Math.h"

class Player : public GameObject
{
	
public:
	Player(Vector2f p_pos, Vector2f p_scale, std::shared_ptr<Image> p_tex);
};