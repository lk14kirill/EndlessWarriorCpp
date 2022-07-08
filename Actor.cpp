#include "Actor.h"
using namespace sf;
Actor::Actor()
{
	object = new RectangleShape(Vector2f(100, 100));
	object->setPosition(Vector2f(500, 500));
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
void Actor::Update(UpdatableObjects* updatables, float time)
{
}
