#include "Fabric.h"
#include "Actor.h"
#include "Enemy.h"
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
void Fabric::UnregisterAndDeleteObject(UpdatableObjects* updatables, DrawableObjects* drawables, Actor* object)
{
	updatables->Remove(object);
	drawables->Remove(object);
	delete object;
}
void Fabric::CreateAndRegisterEnemy(UpdatableObjects* updatables, DrawableObjects* drawables)
{
	RegisterObject(updatables, drawables, new Enemy());
}

void Fabric::CheckIfEnemyNeeded(UpdatableObjects* updatables, DrawableObjects* drawables)
{
	//temporary
	Enemy* enemy = dynamic_cast<Enemy*>(updatables->GetUpdatable<Enemy>());
	if (enemy->fighter->IsDead())
		UnregisterAndDeleteObject(updatables, drawables, updatables->GetUpdatable<Enemy>());
	enemy = nullptr;
	if (updatables->GetUpdatables<Enemy>().size() == 0)
		CreateAndRegisterEnemy(updatables,drawables);
}
