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
    int numnodes, numaris;
    basic_vertex<T> temp;
    basic_link temp2;
    cout << "Ingrese el nombre del archivo a leer: ";
    cin >> (*filename);
    file = new fstream(*filename, ios::in | ios::binary);
    file->seekg(0);
    graph<true, T> *value = new graph<true, T>();
    file->read((char*)isdirected, sizeof(bool));
    file->read((char*)&numnodes, sizeof(int));
    for(int i = 0; i < numnodes; i++)
    {
      file->read((char*)&temp, sizeof(basic_vertex<T>));
      value->insert_nodo(temp.x, temp.y, temp.data);
    }
    file->read((char*)&numaris, sizeof(int));
    for(int i = 0; i < numaris; i++)
    {
      file->read((char*)&temp2, sizeof(basic_link));
      value->make_link(temp2.e1, temp2.e2);
    }
    return value;
  }
};

#endif
