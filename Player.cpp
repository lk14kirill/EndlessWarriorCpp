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

Player::Player() 
{
	controller = new Controller();
	object->setFillColor(sf::Color::Blue);
	object->setPosition(sf::Vector2f(500, 500));
	speed = 5;
	controller->OnMouseClick = boost::bind(&Player::MouseInput, this,_1);
	controller->OnKeyboardClick = boost::bind(&Player::MoveInput, this,_1);
}
void Player::Delegates()
{
	//controller.OnMouseClick = boost::bind(&MouseInput, this);
}
#include "iostream"
void Player::Update(UpdatableObjects* updatables, float time)
{
	enemies = updatables->GetUpdatables<Enemy>();
	lastDeltaTime = time;
	physics->Gravity(this,50,time);
	Move(updatables->updatables);
	if (physics->IsJumping())
		Jump();
	EndUpdate();
}
void Player::Flip() 
{

}
void Player::EndUpdate()
{
	//moveDirection = Vector2f(0, 0);
	enemies.clear();
	lastDeltaTime = 0;
}
void Player::MoveInput(Event event)
{
	/*if (event.key.code == Keyboard::A)
		moveDirection = NormalizedVector::left;
	else if (event.key.code == Keyboard::D)
		moveDirection = NormalizedVector::right;
	else
		moveDirection = Vector2f(0, 0);*/
	if (Keyboard::isKeyPressed(Keyboard::A))
		moveDirection = NormalizedVector::left;
	else if (Keyboard::isKeyPressed(Keyboard::D))
		moveDirection = NormalizedVector::right;
	else
		moveDirection = Vector2f(0, 0);

	if (Keyboard::isKeyPressed(Keyboard::Space))
		Jump();
}
void Player::MouseInput(Event event)
{
	if(event.key.code == Mouse::Left)
	  Attack(this,1);
}
void Player::TryAttack()
{

}
void Player::Move(std::vector<Actor*> updatables)
{
	if(!collider->IsColliding(this,moveDirection , updatables))
		object->setPosition(object->getPosition() + moveDirection * speed);
}
void Player::Jump()
{
		physics->Jump(this, 20, lastDeltaTime);
}

void Player::Attack(FightActor* actor, float damage)
{
	Color c = Mouse::isButtonPressed(Mouse::Left) ? Color::Red : Color::Blue;
	object->setFillColor(c);	
}
Player::~Player()
{
	//delete controller;
}