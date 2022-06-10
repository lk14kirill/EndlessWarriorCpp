#include "Player.h"
#include "Actor.h"
#include "SFML/Graphics.hpp"
#include "NormalizedVector.h"
#include "Physics.h"

Player::Player() 
{
	object->setFillColor(sf::Color::Blue);
	object->setPosition(sf::Vector2f(500, 500));
	speed = 5;
}
void Player::Update(sf::Vector2f playerPos, sf::Vector2f direction, float time)
{
	moveDirection = direction;
	physics->Gravity(this,50,time);
	Move();
	Attack(this,1);
	Jump(time);
}
void Player::Flip() 
{

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
}