#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Math.h"

extern class RenderWindow;

class GameObject
{
	Vector2f pos;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
public:
	GameObject(Vector2f p_pos, SDL_Texture* p_tex);
	Vector2f& getPos()
	{
		return pos;
	}
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();
	//virtual void update() = 0;
	void render(RenderWindow* window);
};