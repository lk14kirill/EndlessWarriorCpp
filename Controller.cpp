#include "Controller.h"
#include "Game.h"
#include "iostream"

void Controller::GetInput(sf::Event event)
{
      OnKeyboardClick(event);
      OnMouseClick(event);
}