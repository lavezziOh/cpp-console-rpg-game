#include <string>
#include <iostream>
using namespace std;
class Item
{
public:
  string name;
  int weight;
  int value;

  Item(string n, int w, int v) ;
  virtual void print(void);
};
//
//class Weapon : public Item
//{
//public:
//  int damage;
//
//  Weapon(int d, string n, int w, int v) :damage(d), Item(n, w, v) {}
//
//  void print(void) { std::cout << name << ": " << weight << " " << value << " " << damage << endl; }
//};
//
//class Armor : public Item
//{
//public:
//  int block;
//  
//  Armor(int b, string n, int w, int v) :block(b), Item(n,w,v) {};
//  
//  void print(void) { std::cout << name << ": " << weight << " " << value << " " << block << endl; }
// };
//
//class Inventory
//{
//public:
//  vector<Item*> items;
//};
