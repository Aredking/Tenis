#pragma once

#include "../include/Display.h"
#include "../include/VRacket.h"


class Game
{

private:

	Display* display;

	const unsigned int WIDTH = 50;
	const unsigned int HEIGHT = 25;

	VRacket racket1;

public:

	Game();

	void run();

};


