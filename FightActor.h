#pragma once
#include "Actor.h"

class Physics;

class FightActor : public Actor
{
public:
	virtual void Attack(FightActor* actor, float damage);
	virtual void Move();
	virtual void Flip();
	FightActor();
	virtual ~FightActor();


	bool facingRight = true;
	float health = 100;
	float speed = 1;

protected:
	Physics* physics;
	float attackDistance = 1;
};

