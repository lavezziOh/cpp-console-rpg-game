#ifndef WEAPON_H
#define WEAPON_H
#include "item.h"
class Weapon : public Item
{
public:
  int damage;

	 Weapon(int damage, std::string name, int weight, int value);

};

#endif
