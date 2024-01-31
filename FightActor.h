#pragma once
#include "Actor.h"
#include "vector" 

class Fighter;
class Collider;
class Physics;

class FightActor : public Actor
{
public:
	virtual void Attack(std::vector<Actor*> updatables , float damage);
	virtual void TryAttack();
	virtual void Move(std::vector<Actor*> updatables);
	virtual void Flip();
	FightActor();
	virtual ~FightActor();

	
	bool facingRight = true;
	float health = 100;
	float speed = 1;
	Fighter* fighter;

protected:
	Physics* physics;
	Collider* collider;
	bool CanAttack();
	void AttackCD(float time);

	float attackCDTime = 2;
	float nextAttackTime;
	float mass = 50;
	float attackDistance = 1;
};

