#pragma once

#include "../include/Display.h"


class Game
{

private:
	Display* display;

	const unsigned short WIDTH = 50;
	const unsigned short HEIGHT = 25;

public:
	Game();

	void run();

};


