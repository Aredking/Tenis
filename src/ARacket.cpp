#include "../include/ARacket.h"

ARacket::ARacket(unsigned int widthRacket) :
	segments(widthRacket)
{
}

const std::vector<Coord>& ARacket::getRacket() const
{
	return segments;
}
