#include <windows.h>
#include <time.h>
#include <vector>
#include "game.h"
#include "creature.h"
#include "npc.h"


Game::Game()
{
	NumberOfCreatures=10;
}
void Game::initialize(int MapMaxX,int MapMaxY,int nCreatures)
{
	
	
	this->MapMaxTilesX=MapMaxX;
	this->MapMaxTilesY=MapMaxY;
	this->NumberOfCreatures=nCreatures;
	srand (time(NULL));
	//RESIZE AND MOVE WINDOW
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect); 
	MoveWindow(console, 0, 0, 1000, 600, TRUE);
	//CREATE CREATURES
	for (int i=0;i<NumberOfCreatures;i++)
	{
		Creature newMob(MapMaxX,MapMaxY-2);	
		
		mobs.push_back(newMob);
	}
}
void Game::update()
{

	
	//We Move Creatures first and check if some is near Hero.
	moveCreatures();
	
	if (Hero.isInCombat(mobs)==false){}
	
	
	//We Move Hero and check again if some Mob is near him.
	Hero.move(MapMaxTilesX,MapMaxTilesY);
	if (Hero.isInCombat(mobs)==false){}
	
	
}
void Game::moveCreatures()
{
	
	for (int i=0;i<NumberOfCreatures;i++)
	{
	
		mobs[i].move(MapMaxTilesX,MapMaxTilesY);
	
		
	}
}
