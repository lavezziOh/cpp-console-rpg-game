#ifndef WEAPON_H
#define WEAPON_H
#include "item.h"
class Weapon : public Item
{
public:
  int damage;
  Weapon();
   
	Weapon(int damage, string n, int w, int v);

};

#endif
