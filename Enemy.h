#pragma once
#include "FightActor.h"
#include "vector"

class Actor;
class Enemy : public FightActor
{
public:
	Enemy();
	void Attack(FightActor* actor, float damage) override;
	void Update(UpdatableObjects* updatables, float time) override;
	void Flip() override;
	void Move(std::vector<Actor*> updatables) override;
	~Enemy();
private:
	void TryAttack() override;
	void CalculateMoveDirection(sf::Vector2f targetPos);
	Actor* target;
	sf::Vector2f moveDirection = sf::Vector2f(0, 0);
};

