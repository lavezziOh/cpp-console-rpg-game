#ifndef GAME_H
#define GAME_H
#include <vector>
#include "creature.h"
#include "npc.h"
class Game
{
public:
	int NumberOfCreatures;
	Game();
	void initialize(int MapMaxX,int MapMaxY,int nCreatures);
	std::vector<int> vect;  
	void update();
private:
    Npc Hero;
	std::vector<Creature> mobs;  
	void moveCreatures();
	
};


#endif
