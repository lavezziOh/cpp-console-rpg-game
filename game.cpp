#include "game.h"
#include <windows.h>
Game::game()
{
	
}
void Game::initialize()
{

	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect); 
	MoveWindow(console, 0, 0, 1000, 600, TRUE);
	
}
