#include "CircleList.h"
#include <iostream>

using namespace std;
using namespace ds_course;

CircleList::CircleList() {
  // cout << "Constructor called." << endl;
  cursor = NULL;
  size = 0;
}

CircleList::~CircleList() {
  // cout << "Destructor called." << endl;
  while(!empty())
    remove();
};

bool CircleList::empty() {
    return cursor == NULL;
};

const int& CircleList::front() const {
    return cursor->next->elem;
};

const int& CircleList::back() const {
    return cursor->elem;
};

void CircleList::add(const int &e) {
  CNode* v = new CNode;
  v->elem = e;

  if (cursor == NULL) {
    v->next = v;
    v->prev = v;
    cursor = v;
  } else {
    if (size == 1)
      cursor->prev = v;
    else
      cursor->next->prev = v;
    v->next = cursor->next;
    v->prev = cursor;
    cursor->next = v;
  }

  size++;
};

void CircleList::remove() {
  CNode* old = cursor->next;
  if (old == cursor)
    cursor = NULL;
  else {
    cursor->next = old->next;
    old->next->prev = cursor;
  }
  delete old;
  size--;
};

void CircleList::advance() {
  cursor = cursor->next;
};

void CircleList::retreat() {
  cursor = cursor->prev;
};

int CircleList::getSize() {
    return size;
};

std::string CircleList::to_str() {
  string list_str;

  for (int i = 0; i < size; i++) {
    list_str.append(to_string(this->back()));
    if (i != size - 1)
      list_str.append(" ");
    this->retreat();
  }

  return list_str;
};
