#include "game.h"
#include <windows.h>
#include "creature.h"
#include <time.h>
#define MAPTILESWIDTH 120
#define MAPTILESHEIGHT 60
Game::Game()
{
	NumberOfCreatures=10;
}
void Game::initialize(int nCreatures)
{
	this->NumberOfCreatures=nCreatures;
	srand (time(NULL));
	//RESIZE AND MOVE WINDOW
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect); 
	MoveWindow(console, 0, 0, 1280, 1024, TRUE);
	//CREATE CREATURES
	//std::vector<Creature> mobs;  
	for (int i=0;i<NumberOfCreatures;i++)
	{
		Creature newMob(80,44);	
		
		mobs.push_back(newMob);
	}
}
void Game::update()
{
	
	moveCreatures();
	
}
void Game::moveCreatures()
{
	
	for (int i=0;i<NumberOfCreatures;i++)
	{
		mobs[i].move(MAPTILESWIDTH,MAPTILESHEIGHT);
		
	}
}
