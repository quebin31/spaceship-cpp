#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>

template <class T>
class NODE{
protected:
  NODE<T>* next;
  T val;
public:
  NODE();
  NODE(const T& );
};

template <class T>
class LINKED_LIST: public NODE<T>{
protected:
  int lsize;
  NODE<T>* head;
  NODE<T>* tail;
public:
  LINKED_LIST();
  ~LINKED_LIST();
  void pushback(NODE<T>* );
  void delete_in(int );
};

#endif // LINKED_LIST_H
