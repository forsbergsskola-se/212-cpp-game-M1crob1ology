#pragma once
#include "../Utils/GameObject.h"
#include "../Utils/Math.h"

class Player : public GameObject
{
	int jump{0};
	const int jumpForce {70};
	const int jumpSpeed{5};
	float groundHeight;
public:
	Player(Vector2f p_pos, Vector2f p_scale, std::shared_ptr<Image> p_tex);
	void handleInput(SDL_Event& event) override;
	void update() override;
	bool dead {};
};