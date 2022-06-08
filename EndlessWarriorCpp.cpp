#include <iostream>
#include <SFML/Graphics.hpp>
#include "Lobby.h"
using namespace sf;

int main()
{
    Lobby* lobby = new Lobby();
    lobby->Start();
    delete lobby;
}

