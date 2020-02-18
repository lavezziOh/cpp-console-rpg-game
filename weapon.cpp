#include <iostream>
#include <string>
#include <vector>
#include "weapon.h"
#include "item.h"
using namespace std;
Weapon::Weapon(int damage, std::string name, int weight, int value) :
    Item(name, weight, value),
    damage(damage)
{ }

