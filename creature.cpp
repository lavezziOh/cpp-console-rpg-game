#include "creature.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <time.h> 


/*
        1                  N
	 8	   2           NW     NE
    7       3         W         E
     6     4           SW     SE
        5   			   S
*/
 Creature::Creature(){
 }
 Creature::Creature(int mapTilesX,int mapTilesY)
{
	//srand (time(NULL));
	COORD coord;
	this->positionX=rand()%mapTilesX+1;
	this->positionY=rand()%mapTilesY+1;
	this->direction=rand()%8+1;
	
	
	coord.X = this->positionX;
	coord.Y = this->positionY;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);//yellow
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout<<"@";
}

void Creature::move(int mapTilesX,int mapTilesY)
{

	COORD coord;
	//N
	if(this->direction==1)
	{
		if (this->positionY==0)
		{
			this->direction=rand()%8+1;
			//this->direction=5;
		}
		if (this->positionY>0){this->positionY=this->positionY-1;}
		coord.X = this->positionX;
		coord.Y = this->positionY;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);//yellow
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		
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
		coord.X = this->positionX;
		coord.Y = this->positionY;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);//yellow
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		
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
		coord.X = this->positionX;
		coord.Y = this->positionY;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);//yellow
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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
		coord.X = this->positionX;
		coord.Y = this->positionY;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);//yellow
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		
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
		coord.X = this->positionX;
		coord.Y = this->positionY;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);//yellow
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		
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
		coord.X = this->positionX;
		coord.Y = this->positionY;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);//yellow
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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
		coord.X = this->positionX;
		coord.Y = this->positionY;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);//yellow
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		
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
		coord.X = this->positionX;
		coord.Y = this->positionY;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);//yellow
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	
	std::cout<<"@";

	
	
}

