#ifndef LINK_H
#define LINK_H
#include "./ForwardList.hpp"
#include "./Vertex.hpp"

template<typename T>
struct Vertex;

template<typename T>
struct Link 
{
  float peso;
  Vertex<T> *partida;
  Vertex<T> *llegada;
  Link(Vertex<T> *_partida, Vertex<T> *_llegada, float _peso = 1) : partida(_partida), llegada(_llegada), peso(_peso){}
};

#endif
