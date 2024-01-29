#include "Fighter.h"
void Fighter::ApplyDamage(float damage)
{
	health -= damage;
}
void Fighter::ApplyHealing(float heal)
{
	health += heal;
	if (health > maxHealth)
		health = maxHealth;
}
Fighter::Fighter(float maxHealth)
{
	Fighter::maxHealth = maxHealth;
	health = maxHealth;
}
float Fighter::GetHealth() 
{
	return health;
}