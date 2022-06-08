#pragma once

#include <vector>
#include "Actor.h"
class IDrawable;

class DrawableObjects
{
public:
	void Add(Actor* drawable);
	void Remove(Actor* drawable);
	std::vector<Actor*> GetDrawables();
	void Draw(sf::RenderWindow* window);
	~DrawableObjects();
	DrawableObjects();
private:
	std::vector<Actor*> drawables;
};

