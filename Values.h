#pragma once
struct Values
{
public:
	const static int windowX = 1920;
	const static int windowY = 1080;
	const static int targetFPS = 200;

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

