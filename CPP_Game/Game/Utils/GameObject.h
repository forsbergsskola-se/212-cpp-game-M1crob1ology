#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "Image.h"
#include "Math.h"

extern class RenderWindow;

class GameObject
{
		
	SDL_Rect currentFrame;
	std::shared_ptr<Image> tex;
protected:
public:
	Vector2f pos;
	Vector2f scale;
	GameObject(Vector2f p_pos, Vector2f p_scale, std::shared_ptr<Image> image);
	Vector2f velocity;
	Vector2f& getScale()
	{
		return scale;
	}
	Image& getTex();
	// add velocity to position
	virtual void update();
	virtual void handleInput(SDL_Event& event){}
	SDL_Rect getCurrentFrame();
	void render(RenderWindow* window);
};