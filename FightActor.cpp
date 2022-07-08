#include "FightActor.h"
#include "Physics.h"
#include "Collider.h"

FightActor::FightActor()
{
	collider = new Collider();
	physics = new Physics();
}
FightActor::~FightActor()
{
	delete physics;
	delete collider;
}
void FightActor::Attack(FightActor* actor,float damage)
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