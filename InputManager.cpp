#include "InputManager.h"
#include "NormalizedVector.h"
using namespace sf;

sf::Vector2f InputManager::GetMoveInput()
{
	if (Keyboard::isKeyPressed(Keyboard::A))
		return NormalizedVector::left;
	if (Keyboard::isKeyPressed(Keyboard::D))
		return NormalizedVector::right;
	return Vector2f(0, 0);
}