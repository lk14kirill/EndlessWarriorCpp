#pragma once

#include <vector>
#include "Actor.h"
class IUpdatable;

class UpdatableObjects
{
public:
	void Add(Actor* updatable);
	void Remove(Actor* updatable);
	std::vector<Actor*> GetUpdatable();
	void Update(sf::Vector2f direction,float time);
	UpdatableObjects();
	~UpdatableObjects();
private:
	std::vector<Actor*> updatables;
};

