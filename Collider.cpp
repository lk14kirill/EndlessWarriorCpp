#include "Collider.h"
#include "Actor.h"
#include "FightActor.h"

void Collider::Update(Actor* actor, sf::Vector2f direction, std::vector<Actor*> objects)
{
	IsColliding(actor, direction, objects);
	//if (IsColliding(actor, direction, objects))
		//actor->GetObject()->setPosition(actor->GetObject()->getPosition() - direction);
}

bool Collider::IsColliding(Actor* actor, sf::Vector2f direction, std::vector<Actor*> objects)
{
	bool result = false;
	for(Actor* act : objects)
	{
		if (!dynamic_cast<const FightActor*>(act) || actor == act)
			continue;

		if (IsInBound(actor,direction, act))
			result = true; 
	}
	return result;
}
#include "iostream"
bool Collider::IsInBound(Actor* actor, sf::Vector2f direction, Actor* act2)
{
	sf::Vector2f size1 = actor->GetObject()->getSize();
	sf::Vector2f actorPos1 = actor->GetObject()->getPosition()-size1 + direction;
	sf::Vector2f size2 = act2->GetObject()->getSize();
	sf::Vector2f actorPos2 = act2->GetObject()->getPosition()-size2;
	
	//std::cout << (Intersect(actorPos1.x, actorPos1.x + size1.x, actorPos2.x, actorPos2.x + size2.x) &&
		//Intersect(actorPos1.y, actorPos1.y + size1.y, actorPos2.y, actorPos2.y + size2.y)) << std::endl;

	return Intersect(actorPos1.x, actorPos1.x + size1.x, actorPos2.x, actorPos2.x + size2.x) &&
		Intersect(actorPos1.y, actorPos1.y + size1.y, actorPos2.y, actorPos2.y + size2.y);
}
bool Collider::Intersect(float min0, float max0, float min1, float max1) 
{
	return max0 <= min1 && min0 >= max1;
}
bool Collider::IntersectY(float min0, float max0, float min1, float max1)
{
	return max0 >= min1 && min0 <= max1;
}