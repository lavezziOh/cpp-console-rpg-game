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
	
	
	this->MapMaxTilesX=MapMaxY;
	this->MapMaxTilesY=MapMaxY;

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

	int size = static_cast<int>(mobs.size());
	moveCreatures();
	if (Hero.isInCombat(mobs)==false){}
	
	
	
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
