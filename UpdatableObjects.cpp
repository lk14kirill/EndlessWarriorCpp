#include "UpdatableObjects.h"
#include "IDrawable.h"

using namespace std;

void UpdatableObjects::Add(Actor* updatable)
{
	updatables.push_back(updatable);
}
void UpdatableObjects::Remove(Actor* updatable)
{
	for (int i = 0; i < updatables.size(); i++)
	{
		if (updatables[i]->GetObject() == updatable->GetObject())
		{
			delete updatable;
			updatables.erase(updatables.begin() + i);
		}
	}
}
void UpdatableObjects::Update(sf::Vector2f playerPos, sf::Vector2f direction, float time)
{
	for(Actor* act : updatables)
	{
		act->Update(playerPos,direction,time);
	}
}
template<typename T> Actor* UpdatableObjects::GetUpdatable()
{
	for(Actor act : updatables)
	{
		if (dynamic_cast<const T*>(act))
			return act;
	}
}
#include "Player.h"
#include <inspectable.h>
Actor* UpdatableObjects::GetPlayer()
{
	for (Actor* act : updatables)
	{
		if (dynamic_cast<const Player*>(act))
			return act;
	}
}
UpdatableObjects::~UpdatableObjects()
{
	for(Actor* act : updatables)
	{
		delete act;
	}
	updatables.clear();
}
UpdatableObjects::UpdatableObjects()
{
	updatables = vector<Actor*>();
}