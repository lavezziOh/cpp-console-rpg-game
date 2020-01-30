#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <conio.h>
#include "creature.h"
#include "map.h"


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


int main()
{
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect); 
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1200, 800, TRUE);
	//////////////////////////////////
	char wasdkeyChar;
	char ccc;
	int done =0;
	//srand (time(NULL)); /* initialize random seed: */
	int mapNumberOfTilesX=40;
	int mapNumberOfTilesY=20;
	Map myMap;
	myMap.CreateMap(mapNumberOfTilesX,mapNumberOfTilesY);
	int x=mapNumberOfTilesX/2;
	int y= mapNumberOfTilesY/2;
	int previosCursorX;
	int previosCursorY;

 	gotoxy(mapNumberOfTilesX/2,mapNumberOfTilesY/2);
	
	Creature mioMob1(mapNumberOfTilesX,mapNumberOfTilesY);
	
	Creature mioMob2(mapNumberOfTilesX,mapNumberOfTilesY);
	
	while(1==1)
	{
		previosCursorX=x;
		previosCursorY=y;
		myMap.show();

		mioMob1.move(mapNumberOfTilesX,mapNumberOfTilesY);
		mioMob2.move(mapNumberOfTilesX,mapNumberOfTilesY);
		gotoxy(previosCursorX,previosCursorY);
		//cout<<mioMob1.positionX<<"-"<<mioMob1.positionY<<"   "<<mioMob2.positionX<<"-"<<mioMob2.positionY;
		wasdkeyChar=getch();
		//cout<<c;
//		system("CLS");
		if(wasdkeyChar=='a' || wasdkeyChar=='d' || wasdkeyChar=='w' || wasdkeyChar=='s')
		{
			if(wasdkeyChar=='a')
			{
				if(x>0)
				{
					gotoxy(x,y);
					ccc = getCursorChar();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),WHITE);
					cout<<ccc;
					x=x-1;
				}
			}
			if(wasdkeyChar=='d')
			{
				if(x<mapNumberOfTilesX-1)
				{		
					gotoxy(x,y);
					ccc = getCursorChar();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),WHITE);
					cout<<ccc;
					x=x+1;
				}
			}
			if(wasdkeyChar=='w')
			{
				if(y>0)
				{		
					gotoxy(x,y);
					ccc = getCursorChar();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),WHITE);
					cout<<ccc;
					y=y-1;
				}
				
			}
			if(wasdkeyChar=='s')
			{
				if(y<mapNumberOfTilesY-1)
				{		
					gotoxy(x,y);
					ccc = getCursorChar();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),WHITE);
					cout<<ccc;
					y=y+1;
				}
			}
			gotoxy(x,y);
			ccc = getCursorChar();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),LIGHTCYAN);
			cout<<ccc;
			gotoxy(x,y);
		
		}
	}


return 0;
}

