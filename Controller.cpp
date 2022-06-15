#include "Controller.h"
#include "Game.h"
#include "iostream"

void Controller::GetInput(sf::Event event)
{
    if (event.type == Event::KeyPressed)
      OnKeyboardClick();
    if (event.type == Event::MouseButtonPressed)
      OnMouseClick();
}