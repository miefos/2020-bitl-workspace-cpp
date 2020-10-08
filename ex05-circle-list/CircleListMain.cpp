#include "CNode.h"
#include "CircleList.h"
#include "OutOfBoundsException.cpp"
#include <iostream>
#include <string>

using namespace std;
using namespace ds_course;

int main() {

const string OUT_OF_BOUNDS_EXCEPTION_MESSAGE = "OutOfBoundsException";

try {
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
        if (position_to_insert > list_size)
          throw OutOfBoundsException(OUT_OF_BOUNDS_EXCEPTION_MESSAGE);


        for (int i = 0; i < (position_to_insert); i++)
          clist->retreat();

        clist->add(num_to_insert);

        for (int i = 0; i < (position_to_insert+1); i++)
          clist->advance();

      } else if (operation == "DEL") {
        int position_to_del;
        cin >> position_to_del;

        if (position_to_del > (list_size-1))
            throw OutOfBoundsException(OUT_OF_BOUNDS_EXCEPTION_MESSAGE);

        for (int i = 0; i < (position_to_del+1); i++)
          clist->retreat();

        clist->remove();

        for (int i = 0; i < (position_to_del); i++)
          clist->advance();

      } else {
            throw OutOfBoundsException(OUT_OF_BOUNDS_EXCEPTION_MESSAGE);
      }
    }

    // display list
    cout << clist->to_str();

    delete clist;

  } catch (OutOfBoundsException e) {
    cout << e.getMessage();
  }

  return 0;
}
