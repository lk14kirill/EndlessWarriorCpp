#pragma once
#include "Actor.h"
class FightActor : public Actor
{
public:
	virtual void Attack(FightActor actor, float damage);
	virtual void Move();
	virtual void Flip();

	bool facingRight = true;
	float health;
	float speed;

};

