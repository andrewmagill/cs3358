#import "vector"
#import "sorting.h"

using namespace std;

void Sorting::quicksort(vector<RESULT> & arr, int left, int right) {
    // adapted from http://www.algolist.net/Algorithms/Sorting/Quicksort
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2].collisions;

      /* partition */
      while (i <= j) {
            while (arr[i].collisions > pivot)
                  i++;
            while (arr[j].collisions < pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i].collisions;
                  arr[i] = arr[j];
                  arr[j].collisions = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            quicksort(arr, left, j);
      if (i < right)
            quicksort(arr, i, right);
};
