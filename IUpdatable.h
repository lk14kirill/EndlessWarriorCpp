#pragma once
class UpdatableObjects;
class IUpdatable
{
public:
	virtual void Update(UpdatableObjects* updatables,float time) = 0;
	virtual ~IUpdatable() {}
};

