#pragma once
#include "SFML/Graphics.hpp"
#include "vector"

class Actor;

class Collider
{
public:
	bool IsColliding(Actor* actor,sf::Vector2f direction, std::vector<Actor*> objects);
private:
	bool IsInBound(Actor* actor, sf::Vector2f direction,  Actor* act);
	bool Intersect(float min0,float max0,float min1,float max1);
	bool IntersectY(float min0, float max0, float min1, float max1);
};

