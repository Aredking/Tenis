#pragma once

#include <iostream>
#include <windows.h>
#include <string>
#include <format>

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
        RACKET = 'H'
    };

    void deactivationCursor();
    void setSizeConsole();
    void setFont();

public:

    Display(const Display& obj) = delete;
    static Display* getInstance(unsigned int width, unsigned int height);

    void drawBounds();
    void printSym(int x, int y, Display::Symbols symbol);

};

