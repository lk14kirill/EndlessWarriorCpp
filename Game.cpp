#include <iostream>
#include <SFML/System.hpp>
#include "Game.h"
#include "Values.h"
#include "InputManager.h"
#include "Fabric.h"
#include "UpdatableObjects.h"
#include "DrawableObjects.h"
#include "Player.h" 

void Game::Init()
{
    fabric->RegisterObject(updateObjects, drawObjects, new Player());
    timeUntilupdate /= Values::targetFPS;
}
    float Game::deltaTime = 0;
void Game::PlayGame()
{
    while ((*window).isOpen() && !isGameEnded)
        GameCycle();
}
using namespace std;
void Game::GameCycle()
{
    WaitNextFrame();
    if(totaltimeUntilUpdate >= timeUntilupdate)
    {
        time = clock->restart().asSeconds();
        WindowClose();
        
        GetInput();
        updateObjects->Update(direction,time);

        (*window).clear(Color::White);
        drawObjects->Draw(window);

        (*window).display();
    }
}
void Game::WaitNextFrame()
{
    totalTimeElapsed = clock->getElapsedTime().asSeconds();
    deltaTime = totalTimeElapsed - prevTimeElapsed;
    prevTimeElapsed = totalTimeElapsed;

    totaltimeUntilUpdate += deltaTime;

}
void Game::WindowClose()
{
    Event event;
    while ((*window).pollEvent(event))
    {
        if (event.type == Event::Closed)
            (*window).close();
    }
}
void Game::GetInput() 
{
    direction = InputManager::GetMoveInput();
}
void Game::CreateClassObjects()
{
    fabric = new Fabric();
    updateObjects = new UpdatableObjects();
    drawObjects = new DrawableObjects();
    direction = Vector2f(0, 0);
    window = new RenderWindow(VideoMode(Values::windowX, Values::windowY), "Game");
    clock = new Clock();
}
Game::Game() 
{
    CreateClassObjects();   
    isGameEnded = false;
}
Game::~Game()
{
    delete window;
    delete updateObjects;
    delete drawObjects;
    delete fabric;
    delete clock;
}