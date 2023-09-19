#include "Actor.h"
using namespace sf;
Actor::Actor()
{
	object = new RectangleShape(Vector2f(100, 100));
	object->setPosition(Vector2f(500, 500));
}
Actor::Actor(Vector2f position,Vector2f size)
{
	object = new RectangleShape(size);
	object->setPosition(position);
	object->setFillColor(Color::Blue);
}
Actor::Actor(Vector2f position, Vector2f size,Color color)
{
	object = new RectangleShape(size);
	object->setPosition(position);
	object->setFillColor(color);
}
Actor::~Actor()
{
	delete object;
}
sf::Drawable* Actor::GetDrawableGO()
{
	return object;
}
sf::RectangleShape* Actor::GetObject()
{
	return object;
}
sf::Vector2f Actor::GetPosition()
{
	return object->getPosition();
}
sf::Vector2f Actor::GetCenterPosition()
{
	return Vector2f(object->getPosition().x + object->getSize().x / 2, object->getPosition().y + object->getSize().y / 2);
}
sf::Vector2f Actor::GetSize()
{
	return object->getSize();
}
void Actor::SetPosition(sf::Vector2f vector)
{
	object->setPosition(vector);
}
void Actor::AddPosition(sf::Vector2f vectorToAdd)
{
	SetPosition(GetPosition() + vectorToAdd);
}
void Actor::Update(UpdatableObjects* updatables, float time)
{
}


