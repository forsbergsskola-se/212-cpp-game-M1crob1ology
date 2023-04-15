#pragma once
#include "../Utils/GameObject.h"
#include "../Utils/Math.h"

class Player : public GameObject
{
	
public:
	Player(Vector2f p_pos, Vector2f p_scale, std::shared_ptr<Image> p_tex);
	void Jump();
	void handleInput(SDL_Event& event) override;
};