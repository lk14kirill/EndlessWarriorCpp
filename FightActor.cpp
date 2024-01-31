#include "FightActor.h"
#include "Physics.h"
#include "Collider.h"
#include "Fighter.h"

FightActor::FightActor()
{
	collider = new Collider();
	physics = new Physics();
	fighter = new Fighter();
}
FightActor::~FightActor()
{
	delete physics;
	delete collider;
	delete fighter;
}
void FightActor::AttackCD(float time)
{
	nextAttackTime += time;
}
bool FightActor::CanAttack()
{
	if(nextAttackTime >= attackCDTime)
	{
		nextAttackTime = 0;
		return true;
	}
	return false;
}
void FightActor::Attack(std::vector<Actor*> updatables,float damage)
{

}
void FightActor::TryAttack()
{

}
void FightActor::Move(std::vector<Actor*> updatables)
{

}
void FightActor::Flip()
{

}