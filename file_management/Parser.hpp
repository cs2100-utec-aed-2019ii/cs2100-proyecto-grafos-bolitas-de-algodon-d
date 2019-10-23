#ifndef PARSER_H
#define PARSER_H
#define FAST_MODE
#include <fstream>
#include "../Graph.hpp"
#include "../Macros.hpp"
#include "./Writer.hpp"
#include "./Reader.hpp"

template<typename T>
class Parser
{
private:
  bool *isdirected;
  fstream *file;
  string *filename;
  void parsevtk(graph<false, T> *element)
  {
    string temp;
    int numnode, numlinks;
    float x, y, z;
  #ifdef FAST_MODE
    file->seekg(83);
  #else
    getline(*file, temp);
    getline(*file, temp);
    getline(*file, temp);
    getline(*file, temp);
    getline(*file, temp);
    *file >> temp;
  #endif
    *file >> numnode;
    *file >> temp;
    for(int i = 0; i < numnode; i++)
    {
      *file >> x >> y >> z;
      element->insert_nodo(x, y);
    }
    getline(*file, temp);
    getline(*file, temp);
    *file >> temp;
    *file >> numlinks;
    *file >> temp;
    for(int i = 0; i < numlinks; i++)
    {
      *file >> numnode;
      int vals[numnode];
      for(int i = 0; i < numnode; i++)
      {
        *file >> vals[i];
      }
      for(int i = 1; i < numnode; i++)
      {
        element->make_link(vals[i-1]-1, vals[i]-1);
      }
    }
  }
public:
  Parser(bool &_isdirected, string *_filename) : file(nullptr)
  {
    isdirected = &_isdirected;
    filename = _filename;
  }
  ~Parser(){}
  void import(void *element)
  {
    string name;
    cout << "Ingrese el nombre del archivo .vtk: ";
    cin >> name;
    graph<false, T> *value = (graph<false,T>*)element;
    file = new fstream(name, ios::in);
    parsevtk(value);
    file->close();
    delete file;
    file = nullptr;
    value->nodos.sort();
    value->links.sort();
  }
  void save(void *element)
  {

  }
  void load(void *element)
  {
    string name;
    cout << "Ingrese el nombre del archivo a cargar: ";
    cin >> name;
  }
};

#endif
