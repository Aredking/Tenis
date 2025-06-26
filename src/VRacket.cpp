#include "../include/VRacket.h"

VRacket::VRacket(unsigned int widthRacket, Coord firstSegment, int upKey_, int downKey_) :
	ARacket(widthRacket),
	upKey(upKey_),
	downKey(downKey_)
{
	for (size_t i = 0; i < segments.size(); ++i)
	{
		segments[i].y = firstSegment.y + i;
		segments[i].x = firstSegment.x;
	}
}


void VRacket::control(unsigned int racketMoveAreaWidth)
{
	if (GetKeyState(upKey) & 0x80)
	{
		if (segments[0].y > 1)
		{
			for (size_t i = 0; i < segments.size(); ++i)
			{
				segments[i].y--;
			}
		}
	}

	if (GetKeyState(downKey) & 0x80)
	{
		if (segments[segments.size() - 1].y < racketMoveAreaWidth - 2)
		{
			for (size_t i = 0; i < segments.size(); ++i)
			{
				segments[i].y++;
			}
		}
	}
}