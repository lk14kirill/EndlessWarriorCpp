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
};

