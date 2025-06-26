#pragma once

#include <vector>

#include "../include/Coord.h"

class ARacket
{
protected:

	std::vector<Coord> segments;
	
public:

	ARacket(unsigned int widthRacket);
	const std::vector<Coord>& getRacket() const;

	virtual void control(unsigned int racketMoveAreaWidth) = 0;

};


