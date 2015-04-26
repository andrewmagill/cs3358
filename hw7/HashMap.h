#ifndef HASHMAP_h
#define HASHMAP_h

#import "List_3358.h"

using namespace cs3358_LL;

// going to make the size of the hash array
// a constant so that the compiler will know
// the size of our array at compile time.
//
// i'm chosing 249989 because it gives us the
// largest array of unsigned ints less than 1 mb
const int SIZE = 249989;

struct HashEntry {
    int key;
    int value;
    HashEntry * next;
};

class HashMap {

private:
    //HashEntry * map [SIZE];
    List_3358<int> * map [SIZE];

public:
    HashMap();

    int hashFunction (const string& str);
    bool insert(const string& str, int value);
    bool remove(int key);
    List_3358<int> * find(const string& str);
    List_3358<int> const& operator[](int index) const;    
    int size();
};

#endif
