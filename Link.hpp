#ifndef LINK_H
#define LINK_H
#include "./ForwardList.hpp"

template<typename T>
struct Vertex;

template<typename T>
struct Link 
{
  float peso;
  Vertex<T> *partida;
  Vertex<T> *llegada;
  int r;
  int g;
  int b;
  Link(Vertex<T> *_partida, Vertex<T> *_llegada, float _peso = 1) : partida(_partida), llegada(_llegada), peso(_peso), r(52), g(177), b(154){}

  ~Link(){}
};

#endif
