#include "../include/Game.h"

Game::Game() :
	racket1(5)
{
	display = Display::getInstance(WIDTH, HEIGHT);
}

void Game::run()
{
	display->drawBounds();

	do
	{
		racket1.control();
	} while (true);
}

