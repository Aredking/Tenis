#pragma once

#include <vector>

class ARacket
{
public:

	static struct Coord
	{
		unsigned int x;
		unsigned int y;
	};

protected:

	std::vector<Coord> segments;
	
public:

	ARacket(unsigned int widthRacket);
	const std::vector<Coord>& getRacket() const { return segments; }

	virtual void control() = 0;

};


