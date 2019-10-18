#ifndef VERTEX_H
#define VERTEX_H
#include "./ForwardList.hpp"
#include "./Link.hpp"

template<typename T>
struct Vertex
{
  List<Vertex<T>*> nodes;
  float x;
  float y;
  T dato;
  List<Link<T>*> links;
  Vertex(T _dato, float _x, float _y) : dato(_dato), x(_x), y(_y){}
  ~Vertex(){
    delete links;
  }
};

#endif
