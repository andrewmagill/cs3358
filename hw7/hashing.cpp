#include <iostream>
#include <string>
#include "HashMap.h"
#include "List_3358.h"

using namespace std;

unsigned int hash_function (const string& str);

int main() {
    HashMap * map = new HashMap();
    map->insert("this is a string", 1);
    map->insert("this is a string", 2);
    map->insert("this is a string", 4);
    map->insert("this is a string", 8);
    List_3358<int> * bucket = map->find("this is a string");

    bucket->reset();

    while(!bucket->atEOL()) {
        cout << bucket->getCurrent() << endl;
        bucket->advance();
    }
    return true;
}
