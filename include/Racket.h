#pragma once

class ARacket
{
private:
	const unsigned short WIDTH_RACKET;
	unsigned int x, y;

public:
	ARacket(unsigned short widthRacket, unsigned short x_, unsigned short y_);

	virtual void draw() const = 0;

};


