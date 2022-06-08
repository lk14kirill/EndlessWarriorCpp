#include "Player.h"
#include "Actor.h"
#include "SFML/Graphics.hpp"
#include "NormalizedVector.h"
#include "Physics.h"

Player::Player() 
{
	object->setFillColor(sf::Color::Blue);
	object->setPosition(sf::Vector2f(500, 500));
	physics = new Physics();
	speed = 5;
}
void Player::Attack(FightActor actor, float damage)
{
}
void Player::Update(sf::Vector2f direction,float time)
{
	object->setPosition(object->getPosition() + direction * speed);
	physics->Gravity(this,50,time);
	Jump(time);
}
void Player::Flip() 
{

}
void Player::Jump(float time)
{
	if (Keyboard::isKeyPressed(Keyboard::Space) || physics->IsJumping())
		physics->Jump(this, 20, time);
}
Player::~Player()
{
	delete physics;
}