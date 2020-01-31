#include "game.h"
#include <windows.h>
Game::Game()
{
	
}
void Game::initialize()
{

	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect); 
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1200, 800, TRUE);
}
