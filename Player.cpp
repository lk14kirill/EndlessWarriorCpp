#include "Player.h"
#include "Actor.h"
#include "SFML/Graphics.hpp"
#include "NormalizedVector.h"
#include "Physics.h"
#include "Controller.h"
#include "boost/bind.hpp"
#include "UpdatableObjects.h"
#include "Enemy.h" 
#include "Collider.h"
#include "Debug.h"
#include "Ray.h"

#include "iostream"
Player::Player() 
{
	controller = new Controller();
	object->setFillColor(sf::Color::Blue);
	object->setPosition(sf::Vector2f(500, 500));
	speed = 7;
	attackDistance = 20;
	ChangeStateTo(State::idle);
	controller->OnMouseClick = boost::bind(&Player::MouseInput, this);
	controller->OnKeyboardClick = boost::bind(&Player::MoveInput, this);
}
void Player::Delegates()
{
}

void Player::Update(UpdatableObjects* updatables, float time)
{
	enemies = updatables->GetUpdatables<Enemy>();
	lastDeltaTime = time;

	Vector2f gforce = physics->Update(this, jumpForce, mass, time);
	if (!collider->IsColliding(this, moveDirection, enemies,CollisionType::both))
		AddPosition(gforce);

	collider->Update(this, moveDirection, enemies);

	Move(enemies);
	AttackCD(lastDeltaTime);
	Attack(updatables->GetUpdatables<Actor>(), 20);

	
	LastUpdate();
	
}
void Player::Flip() 
{

}
void Player::LastUpdate()
{
	enemies.clear();
	lastDeltaTime = 0;
	moveDirection = Vector2f(0, 0);
}
void Player::MoveInput()
{
	if (Keyboard::isKeyPressed(Keyboard::A))
		moveDirection += NormalizedVector::left;
	else if (Keyboard::isKeyPressed(Keyboard::D))
		moveDirection += NormalizedVector::right;
	else
		moveDirection += Vector2f(0, 0);
	moveDirection *= speed;

	if (Keyboard::isKeyPressed(Keyboard::Space))
		Jump();
}
void Player::ChangeStateTo(State newState)
{
	state = newState;
	Debug::Log("Changed state to " + std::to_string(newState), DebugMessageType::INFO);
}
void Player::MouseInput()
{
	if (CanAttack() && Mouse::isButtonPressed(Mouse::Left))
		ChangeStateTo(State::attack);
}
void Player::TryAttack()
{

}
void Player::Move(std::vector<Actor*> updatables)
{
	if (!collider->IsColliding(this, moveDirection, enemies,CollisionType::both))
		AddPosition(moveDirection);

}
void Player::Jump()
{
	if (!collider->IsColliding(this, moveDirection, enemies,CollisionType::both))
		physics->Jump(this, jumpForce, lastDeltaTime);
	else 
		physics->StopJump();

}

void Player::Attack(std::vector<Actor*> updatables, float damage)
{
	if (state != State::attack)
		return;
	Ray* ray = physics->RayCast(enemies, collider, sf::Vector2f(GetCenterPosition().x + GetSize().x / 2, GetCenterPosition().y), 
		NormalizedVector::right, attackDistance);
	if (ray->GetHitInfo() == nullptr)
	{
		Debug::Log("RayHit info is null", DebugMessageType::ERROR);
		ChangeStateTo(State::idle);
		return;
	}
	FightActor* enemy = dynamic_cast<FightActor*>(ray->GetHitInfo());
	enemy->fighter->ApplyDamage(20);
		
	delete ray;
	ChangeStateTo(State::idle);
}
Player::~Player()
{
	delete controller;
	delete fighter;
}