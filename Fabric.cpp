#include "Fabric.h"
#include "Actor.h"
#include "UpdatableObjects.h"
#include "DrawableObjects.h"
void Fabric::RegisterObject(UpdatableObjects* updatables, DrawableObjects* drawables, Actor* object)
{
	updatables->Add(object);
	drawables->Add(object);
}
void Fabric::UnregisterObject(UpdatableObjects* updatables, DrawableObjects* drawables, Actor* object)
{
	updatables->Remove(object);
	drawables->Remove(object);
}