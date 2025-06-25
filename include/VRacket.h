#pragma once

#include <windows.h>
#include <iostream>

#include "../include/ARacket.h"

class VRacket : public ARacket
{
public:

	VRacket(unsigned int widthRacket);

	void control() override;

};