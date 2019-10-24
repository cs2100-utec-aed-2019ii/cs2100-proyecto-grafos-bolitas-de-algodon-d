#include <iostream>
#include "./Screen.hpp"
#include "./Graph.hpp"
using namespace std;

int main()
{

  graph<false,char>* grafo = new graph<false,char>;

  grafo->insert_nodo('a',0,0);
  grafo->insert_nodo('b',3,4);
  grafo->insert_nodo('a',0,0);
  grafo->insert_nodo('b',3,4);
  grafo->make_link(0,1);
  cout<<grafo->BFS('a')->data;
  delete grafo;

  //graph<false,char>* grafo = new graph<false,char>;
  //bool isdirected;
  //string filename;
  //Parser<char> parser(isdirected, &filename);
  //parser.import(grafo);
  //parser.save(grafo);
  //delete grafo;
  //grafo = nullptr;
  //grafo = (graph<false, char>*)parser.load();
  //delete grafo;

  return 0;
}
