#include <iostream>
#include "myTemplatedList.h"

using namespace std;
using namespace cs3358_LL;

void batchProcess(List_3358<int> & list, int cmds[]);
void showList(List_3358<int> & list);

int main() {
  try {
    List_3358<int> myIntList;
    List_3358<int> myOtherIntList = myIntList;

    bool emptylist = myIntList.isEmpty();
    bool endoflist = myIntList.atEOL();

    cout << "empty list: " << emptylist << endl;
    cout << "end of list: " << endoflist << endl;

    if(!emptylist && !endoflist) {
      int current = myIntList.getCurrent();
      cout << current << endl;
    }

    int cmds[] = {4,456,2,-1,878,657,-1,123,32,-1,-1,-1,-1,-1};

    batchProcess(myIntList, cmds);
    showList(myIntList);
/*
    myIntList.insert(435);

    myIntList.insert(1);
    myIntList.insert(324);
    myIntList.insert(76);
    myIntList.insert(657);

    myIntList.remove();

    myIntList.insert(39);
    myIntList.insert(68);

    myIntList.remove();
    myIntList.remove();
    myIntList.remove();
    myIntList.remove();

    myIntList.remove();

    myIntList.insert(65);
*/
  }
  catch (exception const& ex) {
      cerr << "Exception: " << ex.what() <<endl;
      return -1;
  }
}

void batchProcess(List_3358<int> & list, int cmds[]) {
  for(int i = 0; i<14; i++) {
    if(cmds[i]>0) {
      cout << "inserting: " << cmds[i] << endl;
      list.insert(cmds[i]);
    } else {
      cout << "removing" << endl;
      list.remove();
    }
    showList(list);
  }
}

void showList(List_3358<int> & list) {
  list.reset();

  while(!list.atEOL()) {
    cout << list.getCurrent() << endl;
    list.advance();
  }
}
