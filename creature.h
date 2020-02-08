#ifndef CREATURE_H
#define CREATURE_H

class Creature
{
public:
	int maxHealthPoints;
	Creature();
	Creature(int mapTilesX, int mapTilesY);
  	void move(int mapTilesX,int mapTilesY);
private:
  	int direction;
	int positionX;
	int positionY;

};
#endif

