#include "Player.h"
#include "Actor.h"
#include "SFML/Graphics.hpp"
#include "NormalizedVector.h"
#include "Physics.h"
#include "Controller.h"
#include "boost/bind.hpp"

Player::Player() 
{
	controller = new Controller();
	object->setFillColor(sf::Color::Blue);
	object->setPosition(sf::Vector2f(500, 500));
	speed = 5;
	controller->OnMouseClick = boost::bind(&Player::MouseInput, this);
	controller->OnKeyboardClick = boost::bind(&Player::MoveInput, this);
}
void Player::Delegates()
{
	//controller.OnMouseClick = boost::bind(&MouseInput, this);
}
void Player::Update(sf::Vector2f playerPos, sf::Vector2f direction, float time)
{
	physics->Gravity(this,50,time);
	Move();
	Jump(time);
}
void Player::Flip() 
{

}
#include "iostream"
void Player::MoveInput()
{
	if (Keyboard::isKeyPressed(Keyboard::A))
		moveDirection = NormalizedVector::left;
	else if (Keyboard::isKeyPressed(Keyboard::D))
		moveDirection = NormalizedVector::right;
	else
		moveDirection = Vector2f(0, 0);
}
void Player::MouseInput()
{
	Attack(this,1);
}
void Player::Move()
{
	object->setPosition(object->getPosition() + moveDirection * speed);
}
void Player::Jump(float time)
{
	if (Keyboard::isKeyPressed(Keyboard::Space) || physics->IsJumping()) // input temporary
		physics->Jump(this, 20, time);
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