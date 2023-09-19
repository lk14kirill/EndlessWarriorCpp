#pragma once
#include "SFML/Graphics.hpp"
#include "vector"
#include "Values.h"

using namespace std;

class Actor;

class Collider
{
public:
	void Update(Actor* actor, sf::Vector2f direction, std::vector<Actor*> objects);
	bool IsColliding(Actor* actor,sf::Vector2f direction, std::vector<Actor*> objects, CollisionType colType);
private:
	bool IsInBound(Actor* actor, sf::Vector2f direction,  Actor* act,CollisionType);
	bool IsInBoundX(float actorPos1, float actorPos2, float halfSize1, float halfSize2);
	bool IsInBoundY(float actorPos1, float actorPos2, float halfSize1, float halfSize2);
	bool Intersect(float min0,float max0,float min1,float max1);
	bool IntersectY(float min0, float max0, float min1, float max1);
};

