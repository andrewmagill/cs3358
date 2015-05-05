#include <iostream>
#include "array_list_3358.h"

using namespace std;
using namespace cs3358;

int main() {
    List_3358 l = List_3358();

    l.insert(42);
    l.insert(12);
    l.insert(8);

    l.reset();

    while(!l.atEOL()) {
        cout <<  l.getCurrent() << endl;
        l.advance();
    }

    cout << endl;

    l.reset();

    l.insert(15);

    l.reset();

    while(!l.atEOL()) {
        cout <<  l.getCurrent() << endl;
        l.advance();
    }

    cout << endl;

    l.reset();

    //l.advance();

    l.remove();

    l.reset();

    while(!l.atEOL()) {
        cout <<  l.getCurrent() << endl;
        l.advance();
    }

    cout << endl;

    l.reset();

    l.advance();
    l.insert(33);
    l.insert(45);

    l.reset();

    while(!l.atEOL()) {
        cout <<  l.getCurrent() << endl;
        l.advance();
    }

    cout << endl;

    l.reset();

    l.advance();
    l.insert(99);

    l.reset();

    while(!l.atEOL()) {
        cout <<  l.getCurrent() << endl;
        l.advance();
    }

    return 0;
}
