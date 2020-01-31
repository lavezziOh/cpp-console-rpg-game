#include "map.h"
#include <iostream>
#include <cstdlib>
#include "map.h"
#include <windows.h>
#include <string>
#include <time.h> 
#include "map.h" 
void Map::CreateMap(int tilesX, int tilesY)
{
	std::string x[tilesX][tilesY];
	int t=0;
	int k=0;

	int randomNumber=0;
	int randomNumberDensity=0;
	srand (time(NULL));
	COORD coord;

	std::string localmapstring="";
	for (t=0; t <= tilesY-1; ++t)
	{
		for (k=0; k <= tilesX-1; ++k)
		{
			randomNumber=rand()%4+1;
			if(randomNumber==1)x[t][k]=".";
			if(randomNumber==2)x[t][k]=".";
			if(randomNumber==3)x[t][k]=".";
			randomNumberDensity=rand()%3+1;
			
			if(randomNumber==4)
			{
				if(randomNumberDensity==1)
				{
					x[t][k]="4";
				}
				else
				{
					x[t][k]=",";
				}
				
			}
			localmapstring=localmapstring+x[t][k];
  		
		}
		localmapstring=localmapstring+"\n";
	}
	this->mapString=localmapstring;
}
void Map::show()
{
	COORD coord;
  	coord.X = 0;
  	coord.Y = 0;
  	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	std::cout<<this->mapString;
}
