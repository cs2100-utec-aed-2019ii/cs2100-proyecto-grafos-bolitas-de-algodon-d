#ifndef FILESTRUCT_H
#define FILESTRUCT_H
#include <fstream>
#include "../Macros.hpp"

struct file_struct
{
protected:
  bool *isdirected;
  fstream *file;
  string *filename;
public:
  file_struct() : file(nullptr){}
};

#endif
