#ifndef VERTEX_H
#define VERTEX_H
#include "./ForwardList.hpp"
#include "./Link.hpp"

template<typename T>
struct Vertex
{
  List<Vertex<T>*> nodes;
  T data;
  float x;
  float y;
  int r;
  int g;
  int b;
  List<Link<T>*> links;
  List<Link<T>*> links_de_donde;
  Vertex(T _data, float _x, float _y) : data(_data), x(_x), y(_y), r(0), g(0), b(0){}

  unsigned int grade(){
    return this->links.length()+this->links_de_donde.length();
  }
  ~Vertex()
  {
    links.clear();
    nodes.clear();
  }
};

template<typename T>
struct Vertex<T*>
{
  List<Vertex<T*>*> nodes;
  T* data;
  float x;
  float y;
  int r;
  int g;
  int b;
  List<Link<T*>*> links;
  Vertex(T _data, float _x, float _y) : data(_data), x(_x), y(_y){}

  unsigned int grade(){
    return this->links.length();
  }
  ~Vertex()
  {
    delete data;
  }
};

#endif
