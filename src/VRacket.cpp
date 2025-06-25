#include "../include/VRacket.h"

VRacket::VRacket(unsigned int widthRacket) : ARacket(widthRacket) {}


void VRacket::control()
{
	if (GetKeyState('W') & 0x80)
		std::cout << "W";
	else if (GetKeyState('S') & 0x80)
		std::cout << "S";
}