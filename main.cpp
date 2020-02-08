#include <iostream>
#include <cstdlib>
#include <windows.h>

#include <fstream>
#include <vector>
#include <conio.h>

#include "creature.h"
#include "map.h"
#include "game.h"
#include "npc.h"
#include "test.h"

#define MAPTILESWIDTH 120
#define MAPTILESHEIGHT 60

#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
using namespace std;
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
char getCursorChar()    /// Function which returns character on console's cursor position || Totally not copied from the Internet
{
    char c = '\0';
    CONSOLE_SCREEN_BUFFER_INFO con;
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hcon != INVALID_HANDLE_VALUE &&
        GetConsoleScreenBufferInfo(hcon,&con))
    {
        DWORD read = 0;
        if (!ReadConsoleOutputCharacterA(hcon,&c,1,
            con.dwCursorPosition,&read) || read != 1
            )
            c = '\0';
    }
    return c;
}
char readConsoleCharAt(int x,int y)  /// Function which reads character at specific coordinates
{
    gotoxy(x,y);
    char ccccc = getCursorChar();
    return ccccc;
}

void fillCreatures(vector<Creature>&);


//////////////////////////////////////////
//
//
//
// MAIN
//
//
//
//////////////////////////////////////////
int main()
{
	Game game;
	
	game.initialize(100);
	Npc npc123;

	//////////////////////////////////
	char wasdkeyChar;
	char ccc;



	Map myMap;
	myMap.CreateMap(MAPTILESWIDTH,MAPTILESHEIGHT);
	int x=MAPTILESWIDTH/2;
	int y= MAPTILESHEIGHT/2;
	int previosCursorX;
	int previosCursorY;

 	gotoxy(x,y);//go to map center

	while(1==1)
	{
		
		previosCursorX=x;
		previosCursorY=y;
		myMap.show();

		game.update();
  	
		gotoxy(previosCursorX,previosCursorY);
		npc123.move(MAPTILESWIDTH,MAPTILESHEIGHT);
		Sleep(500);
//		wasdkeyChar=getch();
//	
//		if(wasdkeyChar=='a' || wasdkeyChar=='d' || wasdkeyChar=='w' || wasdkeyChar=='s')
//		{
//			if(wasdkeyChar=='a')
//			{
//				if(x>0)
//				{
//					gotoxy(x,y);
//					ccc = getCursorChar();
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),WHITE);
//					cout<<ccc;
//					x=x-1;
//				}
//			}
//			if(wasdkeyChar=='d')
//			{
//				if(x<MAPTILESWIDTH-1)
//				{		
//					gotoxy(x,y);
//					ccc = getCursorChar();
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),WHITE);
//					cout<<ccc;
//					x=x+1;
//				}
//			}
//			if(wasdkeyChar=='w')
//			{
//				if(y>0)
//				{		
//					gotoxy(x,y);
//					ccc = getCursorChar();
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),WHITE);
//					cout<<ccc;
//					y=y-1;
//				}
//				
//			}
//			if(wasdkeyChar=='s')
//			{
//				if(y<MAPTILESHEIGHT-1)
//				{		
//					gotoxy(x,y);
//					ccc = getCursorChar();
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),WHITE);
//					cout<<ccc;
//					y=y+1;
//				}
//			}
//			gotoxy(x,y);
//			ccc = getCursorChar();
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),LIGHTCYAN);
//			cout<<ccc;
//			gotoxy(x,y);
//		
//		}
	}


return 0;
}

void fillCreatures(vector<Creature>& mobs){

	for (int i=0;i<11;i++)
	{
		Creature newMob(MAPTILESWIDTH,MAPTILESHEIGHT);	
		mobs.push_back(newMob);
	}
}

