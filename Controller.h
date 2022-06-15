#pragma once
#include "boost/function.hpp"
#include "SFML/Graphics.hpp" 

class Controller
{
public:
	void GetInput(sf::Event event);
	boost::function<void()> OnMouseClick;
	boost::function<void()> OnKeyboardClick;
};

