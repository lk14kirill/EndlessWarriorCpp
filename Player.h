#pragma once
#include "vector"
#include "FightActor.h"
#include "Fighter.h" 

class Actor;
class Controller;
class UpdatableObjects;
class Player : public FightActor
{
public:
	Player();
	void Attack(FightActor* actor, float damage) override;
	void Update(UpdatableObjects* updatables, float time) override;
	void Flip() override;
	void Move(std::vector<Actor*> updatables) override;
	void Jump();

	~Player();
	Fighter* fighter;
	Controller* controller;

private:
	void TryAttack() override;
	void LastUpdate();
	void Delegates();
	void MouseInput();
	void MoveInput();
	sf::Vector2f GetAttackDirection();

	sf::Vector2f moveDirection = sf::Vector2f(0,0);
	std::vector<Actor*> enemies;
	float jumpForce = 20;
	float lastDeltaTime;
	bool canAttack = true;
};