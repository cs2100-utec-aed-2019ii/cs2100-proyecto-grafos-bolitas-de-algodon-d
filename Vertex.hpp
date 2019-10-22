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
  List<Link<T>*> links;
  Vertex(T _data, float _x, float _y) : data(_data), x(_x), y(_y){}

  unsigned int grade(){
    return this->links.length();
  }
  ~Vertex(){}
};

template<typename T>
struct Vertex<T*>
{
  List<Vertex<T*>*> nodes;
  T* data;
  float x;
  float y;
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
