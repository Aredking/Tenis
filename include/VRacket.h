#pragma once

#include <windows.h>
#include <iostream>

#include "../include/ARacket.h"

class VRacket : public ARacket
{
private:
	
	int upKey, downKey;

public:

	VRacket(unsigned int widthRacket, Coord firstSegment, int upKey_, int downKey_);

	void control(unsigned int racketMoveAreaWidth) override;

};