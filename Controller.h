#pragma once
#include "boost/function.hpp"
#include "SFML/Graphics.hpp" 

class Controller
{
public:
	void GetKeyboardInput();
	void GetMouseInput();
	boost::function<void()> OnMouseClick;
	boost::function<void()> OnKeyboardClick;
};

