#pragma once
#include <SFML/Graphics.hpp>
#include "IUpdatable.h"
#include "IDrawable.h"

class Actor : public IUpdatable,public IDrawable
{
public:
	Actor();
	Actor(sf::Vector2f pos, sf::Vector2f size);
	Actor(sf::Vector2f pos, sf::Vector2f size,sf::Color color);
	virtual ~Actor();
	virtual void Update(UpdatableObjects* updatables, float time);
	sf::Drawable* GetDrawableGO();
	sf::RectangleShape* GetObject();
	sf::Vector2f GetPosition();
	sf::Vector2f GetCenterPosition();
	sf::Vector2f GetSize();
	void SetPosition(sf::Vector2f vector);
	void AddPosition(sf::Vector2f vectorToAdd);
protected:
	sf::RectangleShape* object; // will be as texture
};

