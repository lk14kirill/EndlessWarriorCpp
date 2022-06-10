#include "Physics.h"
#include "Actor.h"
#include "SFML/Graphics.hpp"
#include "Values.h"

using namespace sf;
void Physics::Gravity(Actor * actor,float mass,float deltaTime)
{
	if (isJumping || IsGrounded(actor)) return;

	Vector2f prevPos = actor->GetObject()->getPosition();
	float yAdd = gForce*mass * deltaTime;

	actor->GetObject()->setPosition(Vector2f(prevPos.x,yAdd + prevPos.y));
}
void Physics::Jump(Actor* actor,float force,float deltaTime)
{
	if(canJump && !isJumping)
	{
		StartJump(actor, force);
		Impulse(actor, deltaTime); 
		CheckForEnd(actor);
	}	
	if (isJumping)
	{
		Impulse(actor, deltaTime);
		CheckForEnd(actor);
	}
}
void Physics::StartJump(Actor* actor,float force)
{
	targetYForJump = actor->GetObject()->getPosition().y-force * 10 ;
	isJumping = true;
	canJump = false;
}
void Physics::Impulse(Actor* actor, float deltaTime)
{
	float yToAdd;
	float remainsY = actor->GetObject()->getPosition().y-targetYForJump;
	Vector2f prevPos = actor->GetObject()->getPosition();

	//if jump is close to end,y value dont has to be dependent on deltatime 
	//otherwise it wont end 
	if (remainsY > 3)
		yToAdd = gForce * remainsY * deltaTime;
	else
		yToAdd = 4;

	actor->GetObject()->setPosition(Vector2f(prevPos.x, prevPos.y - yToAdd));
}
void Physics::CheckForEnd(Actor* actor)
{
	if (actor->GetObject()->getPosition().y <= targetYForJump)
	{
		isJumping = false;
		canJump = true;
		targetYForJump = 0;
	}
}
bool Physics::IsJumping()
{
	return isJumping;
}
bool Physics::IsGrounded(Actor * actor) 
{
	float yToCalculate = actor->GetObject()->getPosition().y + actor->GetObject()->getSize().y;
	bool isGrounded = yToCalculate < Values::windowY - groundOffset ? false : true;

	if (isGrounded) canJump = true;
	else canJump = false;

	return isGrounded;
}