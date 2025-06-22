#include "../include/Game.h"

Game::Game()
{
	display = Display::getInstance(WIDTH, HEIGHT);
}

void Game::run()
{
	display->drawBounds();

	do
	{
		
	} while (true);
}

