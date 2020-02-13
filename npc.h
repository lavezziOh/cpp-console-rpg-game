#ifndef NPC_H
#define NPC_H
#include <vector>
#include "Creature.h"
extern const int LIGHTMAGENTA;
extern const int CYAN;
extern const int MAGENTA;
extern const int RED;
extern const int LIGHTCYAN;
class Npc{
public:
	Npc();
	void move(int mapTilesX,int mapTilesY);
	void showHeroPos(int x,int y);
	bool isInCombat(std::vector<Creature>& mobs);
	private:
	int direction;
	int positionX;
	int positionY;
	bool isFighting;
	private:
	int maxHeroHp;
	int currentHeroHp;
		
	
};

#endif
