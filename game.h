#ifndef GAME_H
#define GAME_H
#include <vector>
#include "creature.h"
class Game
{
public:
	
	 game();
	 void initialize();
	 std::vector<int> vect;  
	 void update();
private:

	std::vector<Creature> mobs;  
	void moveCreatures();
	
};


#endif
