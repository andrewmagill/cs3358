#include <iostream>

#include "simple_queue.h"

using namespace std;

int main() {

    SimpleQueue<int> q = SimpleQueue<int>();

    //makeEmpty
    //isEmpty
    //isFull
    //enQueue
    //deQueue

    q.enQueue(42);
    q.enQueue(26);
    q.enQueue(7);
    q.enQueue(6);
    q.enQueue(18);

    int v = q.deQueue();

    cout << v << endl;

    return 0;
}
