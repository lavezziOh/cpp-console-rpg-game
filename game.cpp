#include <windows.h>
#include <time.h>
#include "game.h"
#include "creature.h"
#include "npc.h"

#define MAPTILESWIDTH 120
#define MAPTILESHEIGHT 60
Game::Game()
{
	NumberOfCreatures=10;
}
void Game::initialize(int MapMaxX,int MapMaxY,int nCreatures)
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
	//Npc Hero;
	
	for (int i=0;i<NumberOfCreatures;i++)
	{
		Creature newMob(MapMaxX,MapMaxY-2);	
		
		mobs.push_back(newMob);
	}
}
void Game::update()
{
	//Hero.move();
	moveCreatures();
Hero.move(MAPTILESWIDTH,MAPTILESHEIGHT);
	
}
void Game::moveCreatures()
{
	
	for (int i=0;i<NumberOfCreatures;i++)
	{
		
		mobs[i].move(MAPTILESWIDTH,MAPTILESHEIGHT);
		
	}
}
