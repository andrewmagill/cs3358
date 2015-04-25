#ifndef HASHMAP_h
#define HASHMAP_h

#import "List_3358.h"

// going to make the size of the hash array
// a constant so that the compiler will know
// the size of our array at compile time.
//
// i'm chosing 249989 because it gives us the
// largest array of unsigned ints less than 1 mb
const int SIZE = 249989;

class HashMap {

private:
    struct HashEntry {
        int key;
        int value;
        HashEntry * next;
    };

    HashEntry * map [SIZE];

public:
    HashMap();

    int hashFunction (const string& str);
    bool insert(const string& str, int value);
    bool remove(int key);
    HashEntry * find(int key);
};

#endif
