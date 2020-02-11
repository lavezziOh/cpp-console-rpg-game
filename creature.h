#ifndef CREATURE_H
#define CREATURE_H

class Creature
{
public:
	int maxHealthPoints;
	bool inCombat;
	int positionX;
	int positionY;
	Creature();
	Creature(int mapTilesX, int mapTilesY);
  	void move(int mapTilesX,int mapTilesY);
private:
  	int direction;


};
#endif

