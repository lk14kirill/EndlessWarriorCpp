#pragma once

#include <vector>
#include "Actor.h"
class Player;

class UpdatableObjects
{
public:
	void Add(Actor* updatable);
	void Remove(Actor* updatable);
	void Update(sf::Vector2f playerPos, sf::Vector2f direction, float time);
	UpdatableObjects();
	~UpdatableObjects();
	template<typename T> Actor* GetUpdatable();
	Actor* GetPlayer();
private:
	std::vector<Actor*> updatables;
};

