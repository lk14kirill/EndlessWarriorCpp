#pragma once
#include <SFML/Graphics.hpp>
#include "Actor.h"
class IDrawable
{
public:
	virtual sf::Drawable* GetDrawableGO() = 0;
	virtual ~IDrawable() {}
}; 