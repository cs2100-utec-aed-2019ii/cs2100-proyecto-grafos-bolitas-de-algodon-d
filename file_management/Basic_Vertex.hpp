#ifndef BASIC_VERTEX_H
#define BASIC_VERTEX_H

template<typename T>
struct basic_vertex
{
  float x;
  float y;
  unsigned int grado;
  T data;
  void set(float _x, float _y, unsigned int _grado, T _data)
  {
    x = _x;
    y = _y;
    grado = _grado;
    data = _data;
  }
};

#endif
