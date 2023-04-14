#include "GameObject.h"
#include <SDL.h>
#include <SDL_image.h>

#include "RenderWindow.h"

GameObject::GameObject(Vector2f p_pos, Vector2f p_scale, std::shared_ptr<Image> p_tex) :
pos(p_pos),
scale(p_scale),
tex(p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;
}


Image& GameObject::getTex()
{
	return *tex;
}

SDL_Rect GameObject::getCurrentFrame()
{
	return currentFrame;
}

void GameObject::render(RenderWindow* window)
{
	window->render(*this);
}

void GameObject::update()
{
	
}

