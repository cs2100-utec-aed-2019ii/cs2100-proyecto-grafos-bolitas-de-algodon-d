#ifndef WRITER_H
#define WRITER_H
#include "../Graph.hpp"
#include "./Basic_Vertex.hpp"
#include "./Basic_Link.hpp"
#include "./file_struct.hpp"

template<typename T>
class writer : public file_struct
{
public:
  writer(bool *_isdirected, string *_filename)
  {
    isdirected = _isdirected;
    filename = _filename;
  }
  void exec(void *element)
  {
    int numnodes, numaris;
    basic_vertex<T> temp;
    basic_link temp2;
    if(*filename == "")
    {
      cout << "Ingrese el nombre del archivo a guardar(sin extencion): ";
      cin >> (*filename);
      *filename = *filename + ".owo";
    }
    file = new fstream(*filename, ios::out | ios::binary);
    file->seekp(0);
    graph<true, T> *value = (graph<true, T>*)element;
    numnodes = value->nodos.length();
    numaris = value->links.length();
    file->write((char*)isdirected, sizeof(bool));
    file->write((char*)&numnodes, sizeof(int));
    for(int i = 0; i < numnodes; i++)
    {
      Vertex<T>* stemp = value->nodos.at(i);
      temp.set(stemp->x, stemp->y, stemp->grade(), stemp->data);
      file->write((char*)&temp, sizeof(basic_vertex<T>));
    }
    file->write((char*)&numaris, sizeof(int));
    for(int i = 0; i < numaris; i++)
    {
      Link<T>* stemp = value->links.at(i);
      temp2.set(stemp->peso, value->nodos.index(stemp->partida), value->nodos.index(stemp->llegada));
      file->write((char*)&temp2, sizeof(basic_link));
    }
    file->close();
    delete file;
    file = nullptr;
  }
};

#endif
