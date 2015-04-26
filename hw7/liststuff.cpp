#import <iostream>
#import "List_3358.h"

using namespace std;
using namespace cs3358_LL;

int main() {
    List_3358<int> l;
    l.insert(1);
    l.insert(7);
    l.insert(12);
    l.insert(4);
    l.insert(20);
    l.insert(9);

    vector<int> columns(21, 0);
    vector<vector<int> > matrix(21,columns);

    l.reset();
    while(!l.atEOL()) {
        int doca = l.getCurrent();
        l.remove();
        while(!l.atEOL()) {
            int docb = l.getCurrent();
            matrix[doca][docb] += 1;
            l.advance();
        }
        l.reset();
    }

    for(int i=0; i < 22; i++) {
        for(int j=i; j < 22; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return true;
}
