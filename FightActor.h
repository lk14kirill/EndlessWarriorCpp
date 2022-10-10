#pragma once
#include "Actor.h"
#include "vector" 

class Collider;
class Physics;

class FightActor : public Actor
{
public:
	virtual void Attack(FightActor* actor, float damage);
	virtual void TryAttack();
	virtual void Move(std::vector<Actor*> updatables);
	virtual void Flip();
	FightActor();
	virtual ~FightActor();


	bool facingRight = true;
	float health = 100;
	float speed = 1;

protected:
	Physics* physics;
	Collider* collider;
	
	float mass = 50;
	float attackDistance = 1;
};

