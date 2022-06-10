#include <iostream>
#include <SFML/System.hpp>
#include "Game.h"
#include "Values.h"
#include "InputManager.h"
#include "Fabric.h"
#include "UpdatableObjects.h"
#include "DrawableObjects.h"
#include "Player.h" 
#include "Enemy.h" 

void Game::Init()
{
    fabric->RegisterObject(updateObjects, drawObjects, new Player());
    fabric->RegisterObject(updateObjects, drawObjects, new Enemy());
    timeUntilupdate /= Values::targetFPS;
}
void Game::PlayGame()
{
    while ((*window).isOpen() && !isGameEnded)
        GameCycle();
}
void Game::GameCycle()
{
    WaitNextFrame();
    if(totaltimeUntilUpdate >= timeUntilupdate)
    {
        time = clock->restart().asSeconds();
        WindowClose();
        
        GetInput();
        updateObjects->Update(updateObjects->GetPlayer()->GetObject()->getPosition(), direction, time);

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
void Game::CreateObjects()
{
    fabric = new Fabric();
    updateObjects = new UpdatableObjects();
    drawObjects = new DrawableObjects();
    window = new RenderWindow(VideoMode(Values::windowX, Values::windowY), "Game", Style::Fullscreen);
    clock = new Clock();
    direction = Vector2f(0, 0);
}
void Game::DeleteObjects()
{
    delete window;
    delete updateObjects;
    delete drawObjects;
    delete fabric;
    delete clock;
}
Game::Game() 
{
    CreateObjects();   
    isGameEnded = false;
}
Game::~Game()
{
    DeleteObjects();
}