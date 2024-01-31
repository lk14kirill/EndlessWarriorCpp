#pragma once
#include "SFML/Graphics.hpp"

class Ray;
class Actor;
class Collider;
class Physics
{
public:
	sf::Vector2f Jump(Actor* actor,float force, float time);
	sf::Vector2f Gravity(Actor* actor, float mass, float time);
	bool IsGrounded(Actor* actor);
	bool IsJumping();
	sf::Vector2f Update(Actor* actor, float jumpForce, float mass, float time);
	void StopJump();
	Ray* RayCast(std::vector<Actor*> objects,Collider* col,sf::Vector2f origin, sf::Vector2f direction, float length);
private:
	void StartJump(Actor* actor, float force);
	sf::Vector2f Impulse(Actor* actor,float time);
	void CheckForEnd(Actor* actor);

	bool canJump = true;
	bool isJumping = false;
	float targetYForJump;
	const float gForce = 9.8f;
	float groundOffset = 5;
};

