#ifndef SCREEN_H
#define SCREEN_H
#include<thread>
#include "./Graph.hpp"
#include "./file_management/Parser.hpp"
#include "./Macros.hpp"

template<typename T>
class Screen
{
private:
  graph<false,T> *values;
  graph<true,T> *values2;
  bool isdirected;
public:
  
};

#endif
