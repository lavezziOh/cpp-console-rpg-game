#include "creature.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <time.h> 
 Creature::Creature(int mapTilesX,int mapTilesY)
{
	//srand (time(NULL));
	COORD coord;
	this->positionX=rand()%mapTilesX+1;
	this->positionY=rand()%mapTilesY+1;
	this->direction=rand()%4+1;
	coord.X = this->positionX;
	coord.Y = this->positionY;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);//yellow
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout<<"@";
}
int Creature::returnPos()
{
	return 1;	
}

void Creature::move(int mapTilesX,int mapTilesY)
{
	COORD coord;
		if(this->direction==1)
		{
			if (this->positionY==0)
			{
				this->direction=2;
			}
			else
			{
				this->positionY=this->positionY-1;
			}
		}
		if(this->direction==2)
		{
			if (this->positionY==mapTilesY-1)
			{
				this->direction=1;
			}
			else
			{
				this->positionY=this->positionY+1;
			}
		}
		if(this->direction==3)
		{
			if (this->positionX==0)
			{
				this->direction=4;
			}
			else
			{
				this->positionX=this->positionX-1;
			}
		}
		if(this->direction==4)
		{
			if (this->positionX==mapTilesX-1)
			{
				this->direction=3;
			}
			else
			{
				this->positionX=this->positionX+1;
			}
		}
		coord.X = this->positionX;
		coord.Y = this->positionY;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);//yellow
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		std::cout<<"@";

	
	
}

