#include "FightActor.h"
#include "Physics.h"
FightActor::FightActor()
{
	physics = new Physics();
}
FightActor::~FightActor()
{
	delete physics;
}
void FightActor::Attack(FightActor* actor,float damage)
{

}
void FightActor::Move()
{

}
void FightActor::Flip()
{

}