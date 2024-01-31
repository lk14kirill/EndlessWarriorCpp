#pragma once
#include "SFML/Graphics.hpp"
class Actor;
class Ray
{
public:
	sf::Vector2f GetDirection();
	sf::Vector2f GetOrigin();
	Actor* GetHitInfo();
	Ray(sf::Vector2f origin, sf::Vector2f direction, Actor* hit);
	Ray();
	~Ray();
private:
	sf::Vector2f direction;
	sf::Vector2f origin;
	Actor* hit;
};

