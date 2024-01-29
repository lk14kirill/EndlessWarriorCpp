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

#include "iostream"
Player::Player() 
{
	controller = new Controller();
	fighter = new Fighter(100);
	object->setFillColor(sf::Color::Blue);
	object->setPosition(sf::Vector2f(500, 500));
	speed = 7;
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
void Player::MouseInput()
{
	if(canAttack && Mouse::isButtonPressed(Mouse::Left))
	  Attack(this,1);
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

void Player::Attack(FightActor* actor, float damage)
{
	Color c = Mouse::isButtonPressed(Mouse::Left) ? Color::Red : Color::Blue;
	object->setFillColor(c);	
}
Player::~Player()
{
	delete controller;
	delete fighter;
}