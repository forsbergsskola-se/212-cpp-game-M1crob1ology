#pragma once
#include <SDL.h>
#include <SDL_image.h>

class GameObject
{
	float x, y;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
public:
	GameObject(float p_x, float p_y, SDL_Texture* p_tex);
	float getX();
	float getY();
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();
};