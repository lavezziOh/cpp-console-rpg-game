#ifndef NPC_H
#define NPC_H
#include <vector>
#include "Creature.h"
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
	
};

#endif
