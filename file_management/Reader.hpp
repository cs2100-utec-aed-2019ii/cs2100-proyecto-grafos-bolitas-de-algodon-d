#ifndef READER_H
#define READER_H
#include "../Graph.hpp"
#include "./Basic_Link.hpp"
#include "./Basic_Vertex.hpp"
#include "./file_struct.hpp"

template<typename T>
class reader : public file_struct
{
public:
  reader(bool *_isdirected, string *_filename)
  {
    isdirected = _isdirected;
    filename = _filename;
  }
  void *exec()
  {
  }
};

#endif
