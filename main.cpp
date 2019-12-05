#include <iostream>

#include "./Graph.hpp"
using namespace std;

int main(int argc, char **argv)
{
  //value = new Screen<char>(argc, argv, 640, 480, drawHandler, mouseHandler, keyboardHandler);
  //value->Start();
  //delete value;
  graph<false,char> grafo;
  Vertex<char>* a = new Vertex<char>('a',0,0);
  Vertex<char>* b = new Vertex<char>('b',0,1);
  Vertex<char>* c = new Vertex<char>('c',0,2);
  Vertex<char>* d = new Vertex<char>('d',0,3);
  Vertex<char>* e = new Vertex<char>('e',0,4);
  Vertex<char>* f = new Vertex<char>('f',3,4);
  Vertex<char>* g = new Vertex<char>('g',4,4);
  grafo.insert_nodo(a);
  grafo.insert_nodo(b);
  grafo.insert_nodo(c);
  grafo.insert_nodo(d);
  grafo.insert_nodo(e);
  grafo.insert_nodo(f);
  grafo.insert_nodo(g);
  grafo.make_link(a,b);
  grafo.make_link(b,c);
  grafo.make_link(c,d);
  grafo.make_link(d,e);
  grafo.make_link(e,f);  
  grafo.make_link(a,f);
  grafo.make_link(f,g);
  grafo.make_link(a,g);
  auto dij = grafo.dijkstra(a,g);
  return 0;
}
