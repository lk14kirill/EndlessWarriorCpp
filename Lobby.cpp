#include "Lobby.h"
#include "Game.h"

void Lobby::Start()
{
	Game* game = new Game();
	game->Init();
	game->PlayGame();
	delete game;
}