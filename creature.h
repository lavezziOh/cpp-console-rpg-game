#ifndef CREATURE_H
#define CREATURE_H

class Creature
{
public:
	
	Creature(int mapTilesX, int mapTilesY);
  	void move(int mapTilesX,int mapTilesY);
private:
	int positionX;
  	int positionY;
  	int direction;
	int returnPos();  // de;clare default constructor

};
#endif

