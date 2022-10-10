#include "Physics.h"
#include "Actor.h"
#include "Values.h"

using namespace sf;
Vector2f Physics::Update(Actor* actor, float jumpForce, float mass, float time)
{
	Vector2f direction = Vector2f(0, 0);
	direction += Gravity(actor, mass, time);
	if (IsJumping())
		direction += Jump(actor, jumpForce, time);
	return direction;
}
Vector2f Physics::Gravity(Actor * actor,float mass,float deltaTime)
{
	if (isJumping || IsGrounded(actor)) return Vector2f(0,0);

	Vector2f prevPos = actor->GetObject()->getPosition();
	float yAdd = gForce*mass * deltaTime;

	return Vector2f(0,yAdd);
}
Vector2f Physics::Jump(Actor* actor,float force,float deltaTime)
{
	Vector2f direction;
	if(canJump && !isJumping)
	{
		StartJump(actor, force);
		direction = Impulse(actor, deltaTime); 
		CheckForEnd(actor);
	}	
	if (isJumping)
	{
		direction = Impulse(actor, deltaTime);
		CheckForEnd(actor);
	}
	return direction;
}
void Physics::StartJump(Actor* actor,float force)
{
	targetYForJump = actor->GetObject()->getPosition().y-force * 10 ;
	isJumping = true;
	canJump = false;
}
Vector2f Physics::Impulse(Actor* actor, float deltaTime)
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

    return Vector2f(0,  yToAdd);
}
void Physics::CheckForEnd(Actor* actor)
{
	if (actor->GetObject()->getPosition().y <= targetYForJump)
	{
		StopJump();
	}
}
bool Physics::IsJumping()
{
	return isJumping;
}
void Physics::StopJump()
{
	isJumping = false;
	canJump = true;
	targetYForJump = 0;
}
bool Physics::IsGrounded(Actor * actor) 
{
	float yToCalculate = actor->GetObject()->getPosition().y + actor->GetObject()->getSize().y;
	bool isGrounded = yToCalculate < Values::windowY - groundOffset ? false : true;

	if (isGrounded) canJump = true;
	else canJump = false;

	return isGrounded;
}