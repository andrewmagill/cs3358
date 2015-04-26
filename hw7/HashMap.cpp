#include <iostream>
#include "string"
#include "HashMap.h"

HashMap::HashMap() {
    for(int i = 0; i < SIZE; i++) {
        map[i] = new List_3358<int>;
    }
}
HashMap::~HashMap() {
    for(int i = 0; i < SIZE; i++) {
        delete map[i];
    }
}

int HashMap::hashFunction(const string& str) {
    // bitwise hash function base on JSHash written by Justin Sobel

    // start with a big prime
    unsigned int hashValue = 982418713;

    // we will iterate through the string from back to front,
    // because Dr. Priebe mentioned in class that you find more
    // common pattersn in the beginning of English words that
    // at the end.
    for(int i = str.length()-1; i >= 0; i--)
    {
        // hash := the XOR of hash and the sum of hash shifted
        // 5 bits left, the value of the character, and hash
        // shifted 2 bits right
        hashValue ^= ((hashValue << 5) + str[i] + (hashValue >> 2));
    }

    int key = hashValue % (SIZE - 1);
    return key;
}

bool HashMap::insert(const string& str, int value) {
    int key = hashFunction(str);

    List_3358<int> * bucket = map[key];
    bucket->insert(value);

    return true;
}

bool HashMap::remove(int key) {
    return true;
}

List_3358<int> * HashMap::find(const string& str) {
    int key = hashFunction(str);
    return map[key];
}

List_3358<int> const& HashMap::operator[](int index) const
{
    return * map[index];
}

int HashMap::size() {
    return SIZE;
}
