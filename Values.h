#pragma once
#include <iostream>;
#include "SFML/Graphics.hpp";
struct Values
{
public:
	const static int windowX = 1920;
	const static int windowY = 1080;
	const static int targetFPS = 200;

};
struct EWTexture {
public:
	sf::Texture texture;
	std::string name;
};
enum CollisionType
{
	horizontal,
	vertical,
	both
};
enum DebugMessageType {
	ERROR,
	INFO,
	FUN
};
enum State {
	attack,
	idle,
	moving
};

