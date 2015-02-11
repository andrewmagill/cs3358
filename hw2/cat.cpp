#include <iostream>
#include <string>

using namespace std;

class Cat {
  public:
    Cat(string name = "tom", string color = "black_and_white")
    : _name(name), _color(color) {}
    ~Cat() {}
  
    void setName(string name) {_name = name;}
    string getName() {return _name;}
    void setColor(string color) {_color = color;}
    string getColor() {return _color;}
    void speak() {cout << "meow" << endl;}
  private:
    string _name;
    string _color;
};

int main() {
  Cat litter[5];
  
  Cat cat1("morris", "orange");
  
  cout << cat1.getName() << " is " << cat1.getColor() << endl;
  cat1.speak();
  
  //
  //cout << cat1->getName() << " is " << cat1->getColor() << endl;
  //cat1->speak();
  //
  // error: member reference type 'Cat' is not a pointer; maybe you meant to use '.'?
  //
  
  Cat *cat2pt = new Cat("felix", "black");
  
  cout << cat2pt->getName() << " is " << cat2pt->getColor() << endl;
  cat2pt->speak();
  
  //
  //cat2pt.speak();
  //
  // error: member reference type 'Cat *' is a pointer; maybe you meant to use '->'?
  //
  
  Cat *cat3pt = new Cat;
  
  cout << cat3pt->getName() << " is " << cat3pt->getColor() << endl;
  cat3pt->speak();
  
  //
  //cout << cat3pt.getName() << " is " << cat3pt.getColor() << endl;
  //cat3pt.speak();
  //
  // error: member reference type 'Cat *' is a pointer; maybe you meant to use '->'?
  //
  
  delete cat1;
  delete cat2pt;
  delete cat3pt;
  
  return 0;
}