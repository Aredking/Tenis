#pragma once

#include <windows.h>
#include <iostream>

#include "../include/ARacket.h"

class HRacket : public ARacket
{
public:

	HRacket(unsigned int widthRacket, Coord firstSegment);

	void control(unsigned int racketMoveAreaWidth) override;

};