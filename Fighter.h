#pragma once
class Fighter
{
public:
	Fighter(float maxHealth);
	void ApplyDamage(float damage);
	void ApplyHealing(float health);
	float GetHealth();
	~Fighter();

private:
	float health;
	float maxHealth;
};

