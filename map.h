#ifndef MAP_H
#define MAP_H
#include <string>
class Map
{
public:

	void CreateMap(int tilesX,int tilesY);
	void show();
private:
	std::string mapString;
};
#endif
