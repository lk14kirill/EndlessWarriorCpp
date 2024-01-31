#pragma once
class Fighter
{
public:
	Fighter();
	void ApplyDamage(float damage);
	void ApplyHealing(float health);
	float GetHealth();
	bool IsDead();
	void SetMaxHealth(float newMaxHealth);
	~Fighter();

private:
	float health;
	float maxHealth = 100;
};

