#include "GameObject.h"
#include <SDL.h>
#include <SDL_image.h>

GameObject::GameObject(float p_x, float p_y, SDL_Texture* p_tex) : x(p_x), y(p_y), tex(p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;
}

float GameObject::getX()
{
	return x;
}

float GameObject::getY()
{
	return y;
}

SDL_Texture* GameObject::getTex()
{
	return tex;
}

SDL_Rect GameObject::getCurrentFrame()
{
	return currentFrame;
}


