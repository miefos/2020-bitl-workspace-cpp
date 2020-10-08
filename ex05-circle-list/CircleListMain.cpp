#include "CircleList.h"
#include "CNode.h"
#include <iostream>
#include <string>

// clang++-7 -o main CNode.cpp CircleList.cpp main.cpp; ./main < test1in.txt

using namespace std;
using namespace ds_course;

int main() {

  int num_of_ints;
  cin >> num_of_ints;
  CircleList* clist = new CircleList;

  for (int i = 0; i < num_of_ints; i++) {
    int num_to_add;
    cin >> num_to_add;
    clist->add(num_to_add);
  }

  // cout << clist->getSize();

  int list_size = clist->getSize();

  for (int i = 0; i < list_size; i++) {
    cout << clist->back() << " ";
    clist->retreat();
  }

  cout << endl;

  delete clist;

  return 0;
}