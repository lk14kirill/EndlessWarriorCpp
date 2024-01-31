#pragma once

class UpdatableObjects;
class DrawableObjects;
class IUpdatable;
class IDrawable;
class Actor;

class Fabric
{
public:
	void RegisterObject(UpdatableObjects* updatables, DrawableObjects* drawables, Actor* object);
	void UnregisterObject(UpdatableObjects* updatables, DrawableObjects* drawables, Actor* object);
	void UnregisterAndDeleteObject(UpdatableObjects* updatables, DrawableObjects* drawables, Actor* object);
	void CreateAndRegisterEnemy(UpdatableObjects* updatables, DrawableObjects* drawables);
	void CheckIfEnemyNeeded(UpdatableObjects* updatables, DrawableObjects* drawables);
};

