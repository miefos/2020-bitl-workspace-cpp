#include "CNode.h"
#include "CircleList.h"
#include <iostream>
#include <string>

// clang++-7 -o main CNode.cpp CircleList.cpp main.cpp; ./main < test1in.txt

using namespace std;
using namespace ds_course;

int main() {

  // create list
  int num_of_ints, list_size;
  cin >> num_of_ints;
  CircleList* clist = new CircleList;

  for (int i = 0; i < num_of_ints; i++) {
    int num_to_add;
    cin >> num_to_add;
    clist->add(num_to_add);
  }

  // modify list
  string operation;
  while(cin >> operation) {
    list_size = clist->getSize();

    if (operation == "INS") {
      int position_to_insert, num_to_insert;
      cin >> position_to_insert >> num_to_insert;
      if (position_to_insert > list_size) {
        // THROW ERROR
        cout << " ERROR INS " << endl;
        return -1;
      }

      for (int i = 0; i < (position_to_insert); i++)
        clist->retreat();

      clist->add(num_to_insert);

      for (int i = 0; i < (position_to_insert+1); i++)
        clist->advance();

    } else if (operation == "DEL") {
      int position_to_del;
      cin >> position_to_del;

      if (position_to_del > (list_size-1)) {
        // THROW ERROR
          cout << " ERROR DEL " << endl;
          return -1;
      }


      for (int i = 0; i < (position_to_del+1); i++)
        clist->retreat();

      clist->remove();

      for (int i = 0; i < (position_to_del); i++)
        clist->advance();

    } else {

    }
  }

  // display list
  list_size = clist->getSize();

  for (int i = 0; i < list_size; i++) {
    cout << clist->back() << " ";
    clist->retreat();
  }

  cout << endl;

  delete clist;

  return 0;
}
