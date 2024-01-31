#include "Ray.h"
#include "Actor.h"

sf::Vector2f Ray::GetDirection()
{
	return direction;
}
sf::Vector2f Ray::GetOrigin()
{
	return origin;
}
Actor* Ray::GetHitInfo()
{
	return hit;
}
Ray::Ray(sf::Vector2f _origin, sf::Vector2f _direction, Actor* _hit)
{
	origin = _origin;
	direction = _direction;
	hit = _hit;
}
Ray::Ray()
{
	origin = sf::Vector2f(0,0);
	direction = sf::Vector2f(0, 0);
	hit = nullptr;
}
Ray::~Ray()
{
	
}