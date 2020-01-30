#ifndef CREATURE_H
#define CREATURE_H

class Creature
{
public:
	int positionX;
  	int positionY;
  	int direction;
	Creature(int mapTilesX, int mapTilesY);
  	void move(int mapTilesX,int mapTilesY);
private:

	int returnPos();  // de;clare default constructor

};
#endif

