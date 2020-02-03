#ifndef CREATURE_H
#define CREATURE_H

class Creature
{
public:
		int positionX;
  		int positionY;
	Creature(int mapTilesX, int mapTilesY);
  	void move(int mapTilesX,int mapTilesY);
private:

  	int direction;
	int returnPos();  // de;clare default constructor

};
#endif

