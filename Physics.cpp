#include "Physics.h"
#include "Actor.h"
#include "Values.h"
#include "Ray.h"
#include "Debug.h"
#include "Collider.h"

using namespace sf;
Vector2f Physics::Update(Actor* actor, float jumpForce, float mass, float time)
{
	Vector2f direction = Vector2f(0, 0);
    direction += Gravity(actor, mass, time);

	if (IsJumping())
		 Jump(actor, jumpForce, time);
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
	actor->AddPosition(direction);
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

	actor->AddPosition(Vector2f(0, -yToAdd));

	//We are adding minus,because system calculate ground as max y.
	//So to get up we need to minus.
    return Vector2f(0,  -yToAdd);
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
	float yToCalculate = actor->GetPosition().y + actor->GetObject()->getSize().y;
	bool isGrounded = yToCalculate > Values::windowY - 1.5f * groundOffset 
		&& yToCalculate < Values::windowY - groundOffset ? true : false;

	if (isGrounded) canJump = true;
	else canJump = false;

	return isGrounded;
}
Ray* Physics::RayCast(std::vector<Actor*> updatables,Collider* col,sf::Vector2f origin, sf::Vector2f direction, float length)
{
	sf::Vector2f hitPoint = origin + direction * length;
	Ray* rayHit = new Ray();
	for (Actor* act : updatables)
	{
		if (col->IsPointInBound(hitPoint, act, CollisionType::both))
		{
			Debug::Log("Point in bound", DebugMessageType::INFO);
			rayHit = new Ray(origin, direction, act);
		}
	}
	return rayHit;
}
