#ifndef GAME_H
#define GAME_H
#include <vector>
#include "creature.h"
class Game
{
public:
	int NumberOfCreatures;
	Game();
	void initialize(int nCreatures);
	std::vector<int> vect;  
	void update();
private:
 
	std::vector<Creature> mobs;  
	void moveCreatures();
	
};


#endif
