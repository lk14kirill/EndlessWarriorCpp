#include "Enemy.h"
#include "Actor.h"
#include "SFML/Graphics.hpp"
#include "NormalizedVector.h"
#include "Physics.h"
#include "UpdatableObjects.h"
#include "Player.h"
#include "Collider.h"
#include "Debug.h"
#include "Animator.h"
#include "Values.h"

Enemy::Enemy()
{
	object->setPosition(sf::Vector2f(100, 500));
	animator->AssignImagesForAnimation("Assets/Images/EnemyKnight/", "idle");
	animator->AssignImagesForAnimation("Assets/Images/EnemyKnight/", "attack");
	animator->SetSwitchTime(0.075f);
	animator->playRandomlySameAnimations = true;
	animator->ChangeState(attack);
	speed = 2;
}
void Enemy::Update(UpdatableObjects* updatables, float time)
{
	
	AddPosition(physics->Update(this, 0,mass, time));
	CalculateMoveDirection(updatables->GetUpdatable<Player>()->GetObject()->getPosition());
	animator->Update(time);
	object->setTexture(&animator->currTexture->texture);
	Move(updatables->updatables);
	Attack(updatables->updatables, 1);

	
	LastUpdate();
}
void Enemy::Flip()
{

}
void Enemy::CalculateMoveDirection(sf::Vector2f targetPos)
{
	Vector2f distance = Vector2f(targetPos.x - object->getPosition().x, targetPos.y - object->getPosition().y);
	float length = sqrt(distance.x * distance.x + distance.y * distance.y);  
	moveDirection += Vector2f(distance.x /length, 0);
}
void Enemy::Move(std::vector<Actor*> updatables)
{
	if(!collider->IsColliding(this,moveDirection, updatables,CollisionType::both))
	object->setPosition(object->getPosition() + moveDirection * speed);
}
void Enemy::LastUpdate()
{
	moveDirection = Vector2f(0, 0);
}
void Enemy::Attack(std::vector<Actor*> updatables, float damage)
{
}
void Enemy::TryAttack()
{

}
Enemy::~Enemy()
{
}