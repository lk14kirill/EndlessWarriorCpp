#pragma once
#include "Values.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "boost/function.hpp"

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
	void PollWindowEvents();
	void CreateObjects();
	void DeleteObjects();
	void WaitNextFrame();
	boost::function<void(sf::Event)> OnInput;
	
	bool isGameEnded=false;
	float totalTimeElapsed=0;
	float timeUntilupdate =1;
	float deltaTime = 0;
	float prevTimeElapsed = 0;
	float totaltimeUntilUpdate = 0;
	float time=0;	

	RenderWindow* window;
	UpdatableObjects* updateObjects;
	DrawableObjects* drawObjects;
	Fabric* fabric;
	Vector2f direction;
	Clock* clock;
};


