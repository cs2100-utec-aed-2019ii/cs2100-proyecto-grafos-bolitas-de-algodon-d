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
  string filename;
  Parser<T> *parser;
public:
  Screen()
  {
    values = nullptr;
    values2 = nullptr;
    isdirected = false;
    parser = new Parser<T>(isdirected, &filename);
  }
  ~Screen()
  {
    if(values){delete values; values = nullptr;}
    if(values2){delete values2; values2 = nullptr;}
    delete parser;
  }
  void save()
  {
    if(isdirected)
    {
      parser->save(values2);
    }
    else
    {
      parser->save(values);
    }
  }
  void read()
  {
    void *temp = parser->load();
    if(isdirected)
    {
      values2 = temp;
    }
    else
    {
      values = temp;
    }
  }
};

#endif
