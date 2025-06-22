#pragma once

#include <iostream>
#include <windows.h>
#include <string>
#include <format>

class Display
{
private:

    static Display* instancePtr;
    Display(unsigned short width, unsigned short height);

    const unsigned short WIDTH;
    const unsigned short HEIGHT;
    const unsigned short SCALE;

    static enum class Symbols
    {
        BORDER = '#',
        BOLL = '*',
        RACKET = 'H'
    };

    void deactivationCursor();
    void setSizeConsole();
    void setFont();

public:

    Display(const Display& obj) = delete;
    static Display* getInstance(unsigned short width, unsigned short height);

    void drawBounds();
    void printSym(short x, short y, Display::Symbols symbol);

};

