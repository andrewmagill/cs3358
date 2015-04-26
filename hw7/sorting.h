#ifndef SORTING_h
#define SORTING_h

#import "vector"
#import "string"

using namespace std;

struct RESULT {
    string file_a;
    string file_b;
    int collisions;
};

class Sorting {

public:
    static void quicksort(vector<RESULT> & arr, int left, int right);
};

#endif
