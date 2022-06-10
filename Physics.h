#pragma once
class Actor;
class Physics
{
public:
	void Jump(Actor* actor,float force, float time);
	void Gravity(Actor* actor, float mass, float time);
	bool IsGrounded(Actor* actor);
	bool IsJumping();
private:
	void StartJump(Actor* actor, float force);
	void Impulse(Actor* actor,float time);
	void CheckForEnd(Actor* actor);

	bool canJump = true;
	bool isJumping = false;
	float targetYForJump;
	const float gForce = 9.8f;
	float groundOffset = 5;
};

