#pragma once
class IUpdatable
{
public:
	virtual void Update(sf::Vector2f playerPos ,sf::Vector2f direction,float time) = 0;
	virtual ~IUpdatable() {}
};

