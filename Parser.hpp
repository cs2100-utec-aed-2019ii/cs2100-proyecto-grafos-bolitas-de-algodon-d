#ifndef PARSER_H
#define PARSER_H
#include <fstream>
#include "./Graph.hpp"
#include "./Macros.hpp"

template<typename T>
class Parser
{
private:
  fstream *file;
  string filename;
  graph<T> *element;
public:
  Parser(graph<T> *_element, string _filename)
  {
    element = _element;
    filename = _filename;
    file = new ifstream(filename);
  }
  ~Parser()
  {
    file->close();
    delete file;
  }
};

#endif
