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
  delete grafo;
  return 0;
}
