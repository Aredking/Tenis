#include "../include/Display.h"

Display* Display::instancePtr = nullptr;

Display* Display::getInstance(unsigned int width, unsigned int height)
{
    if (instancePtr == nullptr)
    {
        instancePtr = new Display(width, height);
    }
    return instancePtr;
}

Display::Display(unsigned int width, unsigned int height) : SCALE(2), WIDTH(width), HEIGHT(height)
{
    setSizeConsole();
    deactivationCursor();
    setFont();

    map = new Display::Symbols * [HEIGHT];
    for (size_t i = 0; i < HEIGHT; ++i)
    {
        map[i] = new Display::Symbols[WIDTH];
        for (size_t j = 0; j < WIDTH; ++j)
            map[i][j] = Display::Symbols::SPACE;
    }
}

void Display::deactivationCursor()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(handle, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(handle, &structCursorInfo);
}

void Display::setSizeConsole()
{
    std::string strCommand = std::format("mode con cols={} lines={}", WIDTH * SCALE - 1, HEIGHT);
    const char* command{ strCommand.c_str() };
    system(command);

    SetWindowLongA(GetConsoleWindow(), -16, GetWindowLongA(GetConsoleWindow(), -16) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

void Display::setFont()
{
    CONSOLE_FONT_INFOEX cfi;

    cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);

    cfi.dwFontSize.X = 10;
    cfi.dwFontSize.Y = 22;
    cfi.nFont = 0;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    //wcscpy(cfi.FaceName, L"arial");

    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, &cfi);
}

void Display::setCursorePos(int x, int y)
{

    HANDLE handle;
    COORD coordinates;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X = x * SCALE;
    coordinates.Y = y;
    SetConsoleCursorPosition(handle, coordinates);
}



void Display::drawBounds()
{
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            if (i == 0 || j == 0 || i == HEIGHT - 1 || j == WIDTH - 1) map[i][j] = Display::Symbols::BORDER;
        }
    }
}

void Display::drawRacket(const std::vector<Coord>& segmentsRacket)
{
    for (const auto& segment : segmentsRacket)
        map[segment.y][segment.x] = Display::Symbols::RACKET;
}

void Display::clear()
{
    for (size_t i = 0; i < HEIGHT; ++i)
        for (size_t j = 0; j < WIDTH; ++j)
            map[i][j] = Display::Symbols::SPACE;
}

void Display::display()
{
    for (size_t i = 0; i < HEIGHT; ++i)
        for (size_t j = 0; j < WIDTH; ++j)
        {
            setCursorePos(j, i);
            std::cout << static_cast<char>(map[i][j]);
        }

}

Display::~Display()
{
    for (size_t i = 0; i < HEIGHT; ++i)
        delete[] map[i];
    delete[] map;
}
