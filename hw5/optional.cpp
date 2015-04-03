#include <iostream>

using namespace std;

void f(int arg1);
void f(int arg1, int arg2);
void g(int arg1, int arg2=0);

int main() {
  f(10);
  f(10,10);
  g(11);
  g(11,11);
  return 0;
}

void f(int arg1) {
  cout << arg1 << endl;
}

void f(int arg1, int arg2) {
  cout << arg1 << " " << arg2 << endl;
}

void g(int arg1, int arg2) {
  cout << arg1 << " " << arg2 << endl;
}
