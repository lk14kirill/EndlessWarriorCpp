#include "Collider.h"
#include "Actor.h"
#include "FightActor.h"

using namespace sf;

void Collider::Update(Actor* actor, sf::Vector2f direction, std::vector<Actor*> objects)
{
	if(IsColliding(actor,direction,objects,CollisionType::both))
	{
		if (IsAboveActor(actor, direction, objects) && IsColliding(actor, direction, objects, CollisionType::horizontal))
			actor->AddPosition(Vector2f(direction.x, -1));
		if (IsColliding(actor, direction, objects, CollisionType::horizontal))
			actor->AddPosition(-direction);
	}
}

bool Collider::IsColliding(Actor* actor, sf::Vector2f direction, std::vector<Actor*> objects,CollisionType colType) 
{
	bool result = false;
	for(Actor* act : objects)
	{
		if (!dynamic_cast<const FightActor*>(act) || actor == act)
			continue;

		
		if (IsInBound(actor,direction, act,colType))
			result = true; 
	}
	return result;
}
bool Collider::IsPointInBound(sf::Vector2f point, Actor* act, CollisionType colType)
{
	sf::Vector2f actorPos2 = act->GetCenterPosition();
	sf::Vector2f halfSize2 = sf::Vector2f(act->GetSize().x / 2, act->GetSize().y / 2);

	bool result = false;
	switch (colType)
	{
	case CollisionType::horizontal:
		result = IntersectWithPoint(point.x, actorPos2.x -halfSize2.x, actorPos2.x +halfSize2.x);
		break;
	case CollisionType::vertical:
		result = IntersectYWithPoint(point.y, actorPos2.y - halfSize2.y, actorPos2.y + halfSize2.y);
		break;
	case CollisionType::both:
		result = IntersectWithPoint(point.x, actorPos2.x - halfSize2.x, actorPos2.x + halfSize2.x) &&
			IntersectYWithPoint(point.y, actorPos2.y - halfSize2.y, actorPos2.y + halfSize2.y);
		break;
	}
	return result;
}
bool Collider::IsAboveActor(Actor* actor, sf::Vector2f direction, std::vector<Actor*> objects)
{
	bool result = false;
	for (Actor* act : objects)
	{
		if (!dynamic_cast<const FightActor*>(act) || actor == act)
			continue;


		if (IsPointInBound(sf::Vector2f(act->GetCenterPosition().x,act->GetCenterPosition().y - act->GetSize().y/1.8),actor,CollisionType::vertical))
			result = true;
	}
	return result;
}
bool Collider::IsInBound(Actor* actor, sf::Vector2f direction, Actor* act2,CollisionType colType)
{	 
	sf::Vector2f actorPos1 = actor->GetCenterPosition() + direction;
	sf::Vector2f actorPos2 = act2->GetCenterPosition();
	sf::Vector2f halfSize1 = sf::Vector2f(actor->GetSize().x / 2, actor->GetSize().y / 2);
	sf::Vector2f halfSize2 = sf::Vector2f(act2->GetSize().x / 2, act2->GetSize().y / 2);
	
	bool result = false;
	switch(colType)
	{
	case CollisionType::horizontal:
		result = IsInBoundX(actorPos1.x, actorPos2.x, halfSize1.x, halfSize2.x);
		break;
	case CollisionType::vertical:
		result = IsInBoundY(actorPos1.y, actorPos2.y, halfSize1.y, halfSize2.y);
		break;
	case CollisionType::both:
		result = IsInBoundX(actorPos1.x, actorPos2.x, halfSize1.x, halfSize2.x) &&
			IsInBoundY(actorPos1.y, actorPos2.y, halfSize1.y, halfSize2.y);
		break;
	}
	return result;
}
bool Collider::IsInBoundY(float actorPos1, float actorPos2, float halfSize1, float halfSize2)
{
	return IntersectY(actorPos1 - halfSize1,
		actorPos1 + halfSize1,
		actorPos2 - halfSize2,
		actorPos2 + halfSize2);
}
bool Collider::IsInBoundX(float actorPos1, float actorPos2, float halfSize1, float halfSize2)
{
	return Intersect(actorPos1 - halfSize1,
					 actorPos1 + halfSize1,
					 actorPos2 - halfSize2, 
					 actorPos2 + halfSize2);
}
bool Collider::Intersect(float min0, float max0, float min1, float max1) 
{
	return max0 >= min1 && min0 <= max1;
}
bool Collider::IntersectY(float min0, float max0, float min1, float max1)
{
	return max0 > min1 && min0 < max1;
}
bool Collider::IntersectWithPoint(float x, float min1, float max1)
{
	return x >= min1 && x <= max1;
}
bool Collider::IntersectYWithPoint(float y, float min1, float max1)
{
	return y > min1 && y < max1;
}