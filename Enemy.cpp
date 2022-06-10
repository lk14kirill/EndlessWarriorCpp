#include "Enemy.h"
#include "Actor.h"
#include "SFML/Graphics.hpp"
#include "NormalizedVector.h"
#include "Physics.h"

Enemy::Enemy()
{
	object->setFillColor(sf::Color::Green);
	object->setPosition(sf::Vector2f(100, 500));
	speed = 2;
}
void Enemy::Update(sf::Vector2f playerPos, sf::Vector2f direction, float time)
{
	physics->Gravity(this, 50, time);
	CalculateMoveDirection(playerPos);
	Move();
	Attack(this, 1);
}
void Enemy::Flip()
{

}
void Enemy::CalculateMoveDirection(sf::Vector2f targetPos)
{
	Vector2f distance = Vector2f(targetPos.x - object->getPosition().x, targetPos.y - object->getPosition().y);
	float length = sqrt(distance.x * distance.x + distance.y * distance.y);  
	moveDirection = Vector2f(distance.x /length, 0);
}
void Enemy::Move()
{
	object->setPosition(object->getPosition() + moveDirection * speed);
}
void Enemy::Attack(FightActor* actor, float damage)
{
}
Enemy::~Enemy()
{
}