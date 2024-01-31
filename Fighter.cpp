#include "Fighter.h"
#include "Debug.h"
void Fighter::ApplyDamage(float damage)
{
	health -= damage;
	Debug::Log(std::to_string(health), DebugMessageType::ERROR);
	Debug::Log("OUCH!", DebugMessageType::FUN);
}
void Fighter::ApplyHealing(float heal)
{
	health += heal;
	if (health > maxHealth)
		health = maxHealth;
}
Fighter::Fighter()
{
	health = maxHealth;
}
float Fighter::GetHealth() 
{
	return health;
}
void Fighter::SetMaxHealth(float newMaxHealth)
{
	maxHealth = newMaxHealth;
}
Fighter::~Fighter() 
{

}
bool Fighter::IsDead()
{
	if (health <= 0)
		return true;
	return false;
}