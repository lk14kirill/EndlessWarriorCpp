#pragma once
#include "FightActor.h"
class Controller;
class Player : public FightActor
{
public:
	Player();
	void Attack(FightActor* actor, float damage) override;
	void Update(sf::Vector2f playerPos, sf::Vector2f direction, float time) override;
	void Flip() override;
	void Move() override;
	void Jump(float time);
	~Player();
	Controller* controller;
private:
	void Delegates();
	void MouseInput();
	void MoveInput();
	sf::Vector2f moveDirection = sf::Vector2f(0,0);
};