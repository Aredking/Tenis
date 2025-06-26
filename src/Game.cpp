#include "../include/Game.h"

Game::Game() :
	racket1(5, Coord{ 3,3 }, 'W', 'S'),
	racket2(5, Coord{ 47, 3 }, 0x26, 0x28)
{
	display = Display::getInstance(WIDTH, HEIGHT);
}

void Game::run()
{
	display->drawBounds();
	display->display();

	do
	{
		racket1.control(HEIGHT);
		racket2.control(HEIGHT);

		display->clear();

		display->drawBounds();
		display->drawRacket(racket1.getRacket());
		display->drawRacket(racket2.getRacket());

		display->display();
		Sleep(17);

	} while (true);
}

