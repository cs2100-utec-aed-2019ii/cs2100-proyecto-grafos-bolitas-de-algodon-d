#ifndef FNODE_H
#define FNODE_H
#include <iostream>

template<typename T>
struct Node
{
  T value;
  Node<T> *next;
  Node() : next(nullptr){}
  ~Node()
  {
    if(next){delete next;next = nullptr;}
  }
  Node(T valor): value(valor),next(nullptr){}
  void set_valor(T dato){
    value = dato;
  }
};

//template<typename T>
//struct Node<T*>
//{
//  T* value;
//  Node<T*> *next;
//  Node() : next(nullptr){}
//  Node(T valor): value(valor),next(nullptr){}
//  ~Node()
//  {
//    if(next){delete next;next = nullptr;}
//    delete value;
//  }
//};

#endif
