#pragma once
#include "FightActor.h"
class Physics;
class Player : public FightActor
{
public:
	Player();
	void Attack(FightActor actor, float damage) override;
	void Update(sf::Vector2f direction,float time) override;
	void Flip() override;
	void Jump(float time);
	~Player();
private:
	Physics* physics; // dont know 
};