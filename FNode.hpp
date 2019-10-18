#ifndef FNODE_H
#define FNODE_H
#include <iostream>

template<typename T>
struct Node
{
  T value;
  Node<T> *next;
  Node() : next(nullptr){std::cout << "NO PUNTERO" << std::endl;}
  ~Node()
  {
    if(next){delete next;next = nullptr;}
  }
};

template<typename T>
struct Node<T*>
{
  T* value;
  Node<T> *next;
  Node() : next(nullptr){std::cout << "PUNTERO" << std::endl;}
  ~Node()
  {
    if(next){delete next;next = nullptr;}
    delete value;
  }
};

#endif
