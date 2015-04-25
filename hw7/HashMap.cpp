#include <iostream>
#include "string"
#include "HashMap.h"

HashMap::HashMap() {

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

    int key = hashValue % SIZE;
    return key;
}

bool HashMap::insert(const string& str, int value) {
    HashEntry * newItem;
    newItem->key = hashFunction(str);
    newItem->value = value;

    HashEntry * bucketCursor = map[newItem->key];
    cout << bucketCursor->value << endl;
    return true;
}

bool HashMap::remove(int key) {
    return true;
}

HashMap::HashEntry * HashMap::find(int key) {
    return map[key];
}
