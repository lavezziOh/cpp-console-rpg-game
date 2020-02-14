#include <vector>
using namespace std;

class Item
{
public:
  string name;
  int weight;
  int value;

  Item(string n, int w, int v) : name(n), value(v), weight(w) {}

  virtual void print(void) {}
};

class Weapon : public Item
{
public:
  int damage;

  Weapon(int d, string n, int w, int v) :damage(d), Item(n, w, v) {}

  void print(void) { std::cout << name << ": " << weight << " " << value << " " << damage << endl; }
};

class Armor : public Item
{
public:
  int block;
  
  Armor(int b, string n, int w, int v) :block(b), Item(n,w,v) {};
  
  void print(void) { std::cout << name << ": " << weight << " " << value << " " << block << endl; }
 };

class Inventory
{
public:
  vector<Item*> items;
};

int main(void)
{
  Inventory myInventory;
  Item *myFirstWeapon = new Weapon(6, "Sword", 5, 10);
  Item *myFirstArmor = new Armor(3, "Shield", 4, 8);
  myInventory.items.push_back(myFirstWeapon);
  myInventory.items.push_back(myFirstArmor);
  

  for (int i = 0; i < myInventory.items.size(); i++)
     myInventory.items[i]->print();

  for (int i = 0; i < myInventory.items.size(); i++)
    delete myInventory.items[i];

  return 0;
}
