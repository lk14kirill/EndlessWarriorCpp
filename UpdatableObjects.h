#pragma once

#include <vector>
#include "Actor.h"
class Player;

class UpdatableObjects
{
public:
	void Add(Actor* updatable);
	void Remove(Actor* updatable);
	void Update(float time);
	UpdatableObjects();
	~UpdatableObjects();
	template<typename T> Actor* GetUpdatable();
	template<typename T> std::vector<Actor*> GetUpdatables();
	std::vector<Actor*> updatables;
private:
};

template<typename T> Actor* UpdatableObjects::GetUpdatable()
{
	for (Actor* act : updatables)
	{
		if (dynamic_cast<const T*>(act))
			return act;
	}
}
template<typename T> std::vector<Actor*> UpdatableObjects::GetUpdatables()
{
	std::vector<Actor*> resultUpdatables;
	for (Actor* act : updatables)
	{
		if (dynamic_cast<const T*>(act))
			resultUpdatables.push_back(act);
	}
	return resultUpdatables;
}

