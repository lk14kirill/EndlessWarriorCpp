#include "FightActor.h"
#include "Physics.h"
#include "Collider.h"
#include "Fighter.h"
#include "Animator.h"

FightActor::FightActor()
{
	collider = new Collider();
	physics = new Physics();
	fighter = new Fighter();
	animator = new Animator(0.5f,false);
}
FightActor::~FightActor()
{
	delete physics;
	delete collider;
	delete fighter;
	delete animator;
}
void FightActor::AttackCD(float time)
{
	nextAttackTime += time;
}
void FightActor::AssignTexture(string path)
{
	texture.loadFromFile(path);
	object->setTexture(&texture);
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