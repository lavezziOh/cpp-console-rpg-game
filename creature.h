#ifndef CREATURE_H
#define CREATURE_H
extern const int YELLOW;
extern const int LIGHTRED;

class Creature
{
public:

	int maxHealthPoints;
	int HP;
	bool inCombat;
	bool isAlive;
	int positionX;
	int positionY;
	Creature();
	Creature(int mapTilesX, int mapTilesY);
  	void move(int mapTilesX,int mapTilesY);
  	
private:
  	int direction;


};
#endif

