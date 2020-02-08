#ifndef NPC_H
#define NPC__H

class Npc{
public:
	npc(){};
	void move(int mapTilesX,int mapTilesY);
	private:
	int direction;
	int positionX;
	int positionY;
		
};

#endif
