#include <iostream>
#include "List_3358.h"

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

    myIntList.insert(45);
    cout << "get current --- " << myIntList.getCurrent() << endl;

    int cmds[] = {4,456,2,-1,878,657,-1,123,32,-1,-1,-1,-1,-1};

    cout << "batch process" << endl;

    batchProcess(myIntList, cmds);

    cout << "show my list" << endl;

    showList(myIntList);

    cout << "show my other list" << endl;

    showList(myOtherIntList);

    cout << "insert 98 my list" << endl;

    myIntList.insert(98);

    cout << "insert 62 my other list" << endl;

    myOtherIntList.insert(62);

    cout << "show my other list" << endl;

    showList(myOtherIntList);

    cout << "inserting 34" << endl;
    myIntList.insert(34);
    cout << "inserting 54" << endl;
    myIntList.insert(54);
    cout << "current: " << myIntList.getCurrent() << endl;
    cout << "regress" << endl;
    myIntList.regress();
    myIntList.regress();
    cout << "current: " << myIntList.getCurrent() << endl;
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