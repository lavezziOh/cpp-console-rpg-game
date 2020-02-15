#include "creature.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <time.h> 
#include <string>



Creature::Creature()
{
	this->isAlive=true;
}
Creature::Creature(int mapTilesX,int mapTilesY)
{
	//srand (time(NULL));
	this->maxHealthPoints=10;
	this->HP=10;
	this->isAlive=true;
	COORD coord;
	this->positionX=rand()%mapTilesX;
	this->positionY=rand()%mapTilesY+1;
	this->direction=rand()%8+1;
//	int x=rand()%2;
//	if(x==1)
//	{
		this->inCombat=false;	
//	}
//	else
//	{
//		this->inCombat=true;	
//	}
		
	coord.X = this->positionX;
	coord.Y = this->positionY;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),YELLOW);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout<<"@";
}


void Creature::move(int mapTilesX,int mapTilesY)
{
	/*
        1                  N
	 8	   2           NW     NE
    7       3         W         E
     6     4           SW     SE
        5   			   S
*/
	COORD coord;
	//move creature if not in combat
	if(this->isAlive==true && this->inCombat==false)
	{
		//N
		if(this->direction==1)
		{
			if (this->positionY==0)
			{
				this->direction=rand()%8+1;
				//this->direction=5;
			}
			if (this->positionY>0){this->positionY=this->positionY-1;}
		}
		//S
		if(this->direction==5)
		{
			if (this->positionY==mapTilesY-1)
			{
				this->direction=rand()%8+1;
				//this->direction=1;
			}
			if (this->positionY<mapTilesY-1){this->positionY=this->positionY+1;}
		}
		//E
		if(this->direction==3)
		{
			if (this->positionX==mapTilesX-1)
			{
				//this->direction=rand()%8+1;
				this->direction=7;
				this->direction=rand()%8+1;
			}
			if (this->positionX<mapTilesX-1){this->positionX=this->positionX+1;}
		}
		//W
		if(this->direction==7)
		{
			if (this->positionX==0)
			{
				//this->direction=rand()%8+1;
				this->direction=3;
				this->direction=rand()%8+1;
			}
			if (this->positionX>0){this->positionX=this->positionX-1;}
		}
		//NE
		if(this->direction==2)
		{
			if (this->positionX==0 || this->positionY==0)
			{
				//this->direction=rand()%8+1;
				this->direction=6;
				this->direction=rand()%8+1;
			}
		
			if (this->positionX<mapTilesX-1){this->positionX=this->positionX+1;}
			if (this->positionY>0){this->positionY=this->positionY-1;}
		}
		//SW
		if(this->direction==6)
		{
				if (this->positionX==0 || this->positionY==mapTilesY-1)
			{
				this->direction=2;
				this->direction=rand()%8+1;
			}
			if (this->positionX>0){this->positionX=this->positionX-1;}
			if (this->positionY<mapTilesY-1){this->positionY=this->positionY+1;}
		}
		//SE
		if(this->direction==4)
		{
			if (this->positionX==mapTilesX-1 || this->positionY==mapTilesY-1)
			{
				
				this->direction=8;
				this->direction=rand()%8+1;
			}
		
			if (this->positionX<mapTilesX-1){this->positionX=this->positionX+1;}
			if (this->positionY<mapTilesY-1){this->positionY=this->positionY+1;}
		}
		//NW
		if(this->direction==8)
		{
			if (this->positionX==0 || this->positionY==0)
			{
				this->direction=4;
				this->direction=rand()%8+1;
			}
			if (this->positionX>0){this->positionX=this->positionX-1;}
			if (this->positionY>0){this->positionY=this->positionY-1;}
		}
		coord.X = this->positionX;
		coord.Y = this->positionY;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),YELLOW);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		std::cout<<"@";
	}

		//change creature color when in combat
		

	if (this->isAlive==true && this->inCombat==true)
	{
		coord.X = this->positionX;
		coord.Y = this->positionY;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),LIGHTRED);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		std::cout<<"@";
	}
	if (this->isAlive==false)
	{
		coord.X = this->positionX;
		coord.Y = this->positionY;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),YELLOW);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		std::cout<<"X";
	}
	
}

