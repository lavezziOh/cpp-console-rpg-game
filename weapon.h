#ifndef WEAPON_H
#define WEAPON_H
#include "item.h"
class Weapon : public Item
{
public:
  int damage;
  Weapon();
   
	Weapon(int damage);
  ////void print(void) { std::cout << name << ": " << weight << " " << value << " " << damage << endl; }
};

#endif
