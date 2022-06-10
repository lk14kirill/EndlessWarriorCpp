#pragma once
#include "Values.h"
#include <vector>
#include <SFML/Graphics.hpp>

class UpdatableObjects;
class DrawableObjects;
class Fabric;

using namespace sf;

class Game
{
public:
	Game();
	void GameCycle();
	void Init();
	void PlayGame();
	~Game();
private:
	void WindowClose();
	void GetInput();
	void CreateObjects();
	void DeleteObjects();
	void WaitNextFrame();
	
	bool isGameEnded=false;
	float totalTimeElapsed=0;
	float timeUntilupdate =1;
	float deltaTime = 0;
	float prevTimeElapsed = 0;
	float totaltimeUntilUpdate = 0;
	float time=0;	

	UpdatableObjects* updateObjects;
	DrawableObjects* drawObjects;
	Fabric* fabric;
	RenderWindow* window;
	Vector2f direction;
	Clock* clock;
};

