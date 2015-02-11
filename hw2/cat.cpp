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
  
  cout << sizeof(litter) << endl;
  cout << sizeof(*litter) << endl;
  cout << (sizeof(litter)/sizeof(*litter)) << endl;
  
  for(int i = 0; i < 5; i++) {
    cout << litter[i].getName() << endl;
  }
  
  for(int i = 0; i < 5; i++) {
    litter[i] = Cat("bobby","black/white");
  }
  
  for(int i = 0; i < 5; i++) {
    cout << litter[i].getName() << endl;
  }
  
  //
  //for(int i = 0; i < 5; i++) {
  //  litter[i] = new Cat("marm","orange");
  //}
  //
  // error: no viable overloaded '='
  // note: candidate function (the implicit copy assignment operator) not viable: no known conversion from 'Cat *' to
  //    'const Cat' for 1st argument; dereference the argument with *
  
  Cat * newLitter[5];
  
  cout << sizeof(newLitter) << endl;  
  cout << sizeof(*newLitter) << endl;
  cout << (sizeof(newLitter)/sizeof(*newLitter)) << endl;
  
  for(int i = 0; i < 5; i++) {
    newLitter[i] = new Cat("marm","orange");
  }
  
  for(int i = 0; i < 5; i++) {
    cout << newLitter[i]->getName() << endl;
  }
  
  //
  //delete newLitter;
  //
  //error: cannot delete expression of type 'Cat *[5]'
  //
  
  cout << sizeof(newLitter) << endl;
  
  for(int i = 0; i < 5; i++) {
    delete newLitter[i];
  }
  
  // i don't understand what's happening here /\
  
  cout << sizeof(newLitter) << endl;
  
  for(int i = 0; i < 5; i++) {
    cout << newLitter[i]->getName() << endl;
    cout << "hi";
  }
  
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
  
  //delete cat1;
  // error: cannot delete expression of type 'Cat'
  delete cat2pt;
  delete cat3pt;
  
  return 0;
}