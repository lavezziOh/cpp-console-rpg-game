#ifndef WEAPON_H_H
#define WEAPON_H
#include "item.h"
class Weapon : public Item
{
public:
  int damage;

  Weapon(int damage) ;

  //void print(void) { std::cout << name << ": " << weight << " " << value << " " << damage << endl; }
};

#endif
