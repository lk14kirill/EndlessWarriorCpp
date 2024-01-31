#pragma once
#include "vector"
#include "FightActor.h"
#include "Fighter.h" 

class Actor;
class Controller;
class UpdatableObjects;
class Player : public FightActor
{
	enum State {
		attack,
		idle,
		moving
	};
public:
	Player();
	void Update(UpdatableObjects* updatables, float time) override;
	void Flip() override;
	void Move(std::vector<Actor*> updatables) override;
	void Jump();

	~Player();
	Controller* controller;

private:
	void Attack(std::vector<Actor*> updatables, float damage) override;
	void TryAttack() override;
	void LastUpdate();
	void Delegates();
	void MouseInput();
	void MoveInput();
	void ChangeStateTo(State state);
	

	sf::Vector2f attackOrigin;
	sf::Vector2f moveDirection = sf::Vector2f(0,0);
	std::vector<Actor*> enemies;
	float jumpForce = 20;
	float lastDeltaTime;
	
	
	State state;

};
