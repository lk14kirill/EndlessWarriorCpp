#pragma once
#include <SFML/Graphics.hpp>
#include "IUpdatable.h"
#include "IDrawable.h"

class Actor : public IUpdatable,public IDrawable
{
public:
	Actor();
	virtual ~Actor();
	virtual void Update(UpdatableObjects* updatables, float time);
	sf::Drawable* GetDrawableGO();
	sf::RectangleShape* GetObject();
protected:
	sf::RectangleShape* object; // will be as texture
};

