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
void UpdatableObjects::Update(float time)
{
	for(Actor* act : updatables)
	{
		act->Update(this,time);
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