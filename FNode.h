#ifndef FNODE_H
#define FNODE_H

template<typename T>
struct Node
{
  T value;
  Node<T> *next;
  Node() : next(nullptr){}
};

#endif
