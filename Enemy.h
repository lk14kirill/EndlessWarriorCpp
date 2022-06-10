#pragma once
#include "FightActor.h"
class Enemy : public FightActor
{
public:
	Enemy();
	void Attack(FightActor* actor, float damage) override;
	void Update(sf::Vector2f playerPos, sf::Vector2f direction, float time) override;
	void Flip() override;
	void Move() override;
	~Enemy();
private:
	void CalculateMoveDirection(sf::Vector2f targetPos);
	sf::Vector2f moveDirection = sf::Vector2f(0, 0);
};

