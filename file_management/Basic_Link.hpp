#ifndef BASIC_LINK_H
#define BASIC_LINK_H

struct basic_link 
{
  float peso;
  int e1;
  int e2;
  void set(float _peso, int _e1, int _e2)
  {
    peso = _peso;
    e1 = _e1;
    e2 = _e2;
  }
};

#endif
