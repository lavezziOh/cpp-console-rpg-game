#include "npc.h"
#include "creature.h"
#include <windows.h>
#include <iostream>
#include <vector>

Npc::Npc()
{
	isFighting=false;
	maxHeroHp=30;
	currentHeroHp=30;
	direction=4;
	positionX=2;
	positionY=0;
	COORD coord;
	coord.X = this->positionX;
	coord.Y = this->positionY;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),LIGHTMAGENTA);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout<<"H";
}

void Npc::showHeroPos(int x,int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),LIGHTMAGENTA);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout<<this->positionX<<"---"<<this->positionY<<"    ";
}
bool Npc::isInCombat(std::vector<Creature>& mobs)
{
	showHeroPos(60,0);
	std::string isdead;
	int newY;
	for (int i=0;i<10;i++)
	{
		COORD coord;
		coord.X = 60;
		newY=i+1;
		coord.Y = newY;
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),LIGHTCYAN);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		if(mobs[i].isAlive==false)
		{
			isdead="is dead";
		}
		else
		{
			isdead="is alive";
		}
		std::cout<<"Mob"<<i<<" Hp:"<<mobs[i].HP<<" "<<isdead <<" "<<mobs[i].positionX<<" "<<mobs[i].positionY<<"           ";
		
		
		
		
		//Check if some Mob is close to Hero
		if((mobs[i].isAlive==true) && (mobs[i].positionX==this->positionX || mobs[i].positionX==this->positionX-1 || mobs[i].positionX==this->positionX+1) && (mobs[i].positionY==this->positionY || mobs[i].positionY==this->positionY-1 || mobs[i].positionY==this->positionY+1))
		{
					
			mobs[i].inCombat=true;
			this->isFighting=true;
			//////////////////////
			//Hero Damage
			//////////////////////
			int damage=rand()%5+1;
			mobs[i].HP=	mobs[i].HP-damage;
			//Mob is dead		
			if(mobs[i].HP<=0 && mobs[i].isAlive==true)
			{
				mobs[i].isAlive=false;
				this->isFighting=false;
				coord.X = 60;
				newY=i+20;
				coord.Y = newY;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
				std::cout<<"Hero Hp:"<<currentHeroHp<<"("<<damage<<")"<<" Mob "<<i<<" is DEAD       ";
				mobs.erase(mobs.begin() + i);
				return false;
			}
			else
			{
				coord.X = 70;
				coord.Y = 15;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),RED);
				std::cout<<"                                                  "<<std::endl;	
				if(mobs[i].inCombat==true)
				{
					coord.X = 70;
					coord.Y = 15;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),RED);
					std::cout<<" WAR " ;
					coord.X = 60;
					coord.Y = i+20;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),RED);
					std::cout<<"Hero Hp:"<<currentHeroHp<<"("<<damage<<")"<<" MobHP"<<i<<":"<<mobs[i].HP<<"  ";	
				}
				else
				{
					coord.X = 60;
					coord.Y = 16;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),RED);
					std::cout<<"                                                  ";	
				}
				
			}
		
			return true;
		}
	
	
		
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),LIGHTMAGENTA);
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),LIGHTMAGENTA);
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),LIGHTMAGENTA);
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),MAGENTA);
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),MAGENTA);
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),MAGENTA);
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),MAGENTA);
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),MAGENTA);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		}
	}
	else
	{
		coord.X = this->positionX;
		coord.Y = this->positionY;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),CYAN);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	std::cout<<"H";

	
	
}

