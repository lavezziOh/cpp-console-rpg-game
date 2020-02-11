#include "npc.h"
#include "creature.h"
#include <windows.h>
#include <iostream>
#include <vector>

Npc::Npc()
{
	isFighting=false;
	direction=4;
	positionX=2;
	positionY=0;
	COORD coord;
	coord.X = this->positionX;
	coord.Y = this->positionY;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);//LIGHT MAGENTA
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout<<"H";
}

void Npc::showHeroPos(int x,int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);//LIGHT MAGENTA
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout<<this->positionX<<"---"<<this->positionY<<"    ";
}
bool Npc::isInCombat(std::vector<Creature>& mobs)
{
	showHeroPos(60,0);
	int newY;
	for (int i=0;i<10;i++)
	{
		COORD coord;
		coord.X = 60;
		newY=i+1;
		coord.Y = newY;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);//LIGHT MAGENTA
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		std::cout<<mobs[i].positionX<<" vv "<<i<<" vv "<<mobs[i].positionY<<"     ";	
		if((mobs[i].positionX==this->positionX || mobs[i].positionX==this->positionX-1 || mobs[i].positionX==this->positionX+1) && (mobs[i].positionY==this->positionY || mobs[i].positionY==this->positionY-1 || mobs[i].positionY==this->positionY+1))
		{
			coord.X = 70;
			coord.Y = 15;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);//LIGHT MAGENTA
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			std::cout<<" WAR " ;		
			mobs[i].inCombat=true;
			this->isFighting=true;
			return true;
		}
	
		//mobs[i].move(MAPTILESWIDTH,MAPTILESHEIGHT);
	
		
	}
	return false;
	
}
void Npc::move(int mapTilesX,int mapTilesY)
{

	COORD coord;
	if(this->isFighting==false)
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
			coord.X = this->positionX;
			coord.Y = this->positionY;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);//LIGHT MAGENTA
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);//LIGHT MAGENTA
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);//LIGHT MAGENTA
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//MAGENTA
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//MAGENTA
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//MAGENTA
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//MAGENTA
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//MAGENTA
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		}
	}
	else
	{
		coord.X = this->positionX;
		coord.Y = this->positionY;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//CYAN
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	std::cout<<"H";

	
	
}

