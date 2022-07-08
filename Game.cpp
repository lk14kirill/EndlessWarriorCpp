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
#include "boost/bind.hpp"
#include "Controller.h"

void Game::Init()
{
    Player* player = new Player();
    fabric->RegisterObject(updateObjects, drawObjects, player);
    fabric->RegisterObject(updateObjects, drawObjects, new Enemy());
    timeUntilupdate /= Values::targetFPS;
    OnInput = boost::bind(&Controller::GetInput, player->controller,_1);
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
        PollWindowEvents();

        updateObjects->Update(time);

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
void Game::PollWindowEvents()
{
    Event event;
    while ((*window).pollEvent(event))
    {
        if (event.type == Event::Closed)
            (*window).close();
        //if (event.type == Event::KeyPressed || event.type == Event::MouseButtonPressed)
            OnInput(event);
    }
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