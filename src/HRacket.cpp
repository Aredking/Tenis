#include "../include/HRacket.h"

HRacket::HRacket(unsigned int widthRacket) : ARacket(widthRacket) {}


void HRacket::control()
{
	if (GetKeyState('W'))
		std::cout << "A";
	else if (GetKeyState('S'))
		std::cout << "D";
}
