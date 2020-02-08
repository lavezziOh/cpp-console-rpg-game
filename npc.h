#ifndef NPC_H
#define NPC_H

class Npc{
public:
	Npc();
	void move(int mapTilesX,int mapTilesY);
	private:
	int direction;
	int positionX;
	int positionY;
	
};

#endif
