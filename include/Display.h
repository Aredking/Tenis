#pragma once

#include <iostream>
#include <windows.h>
#include <string>
#include <format>
#include <vector>

#include "../include/Coord.h"

class Display
{
private:

    static Display* instancePtr;
    Display(unsigned int width, unsigned int height);

    const unsigned int WIDTH;
    const unsigned int HEIGHT;
    const unsigned int SCALE;

    static enum class Symbols
    {
        BORDER = '#',
        BOLL = '*',
        RACKET = 'H',
        SPACE = ' '
    };

    void deactivationCursor();
    void setSizeConsole();
    void setFont();

    void setCursorePos(int x, int y);

    Display::Symbols** map;

public:

    Display(const Display& obj) = delete;
    static Display* getInstance(unsigned int width, unsigned int height);

    void drawBounds();
    void drawRacket(const std::vector<Coord>& segmentsRacket);

    void clear();
    
    void display();

    ~Display();

};

