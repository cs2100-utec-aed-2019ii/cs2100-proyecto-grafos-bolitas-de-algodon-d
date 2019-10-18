#include <iostream>
#include "./Screen.hpp"
#include "./Graph.hpp"
using namespace std;

int main()
{
  graph<char>* grafo = new graph<char>;
  Vertex<char>* primero = new Vertex<char>('a',0,0);
  Vertex<char>* segundo = new Vertex<char>('b',3,4);
  grafo->insert_nodo(primero);
  grafo->insert_nodo(segundo);
  grafo->make_link(primero,segundo);
  cout<<primero->dato<<endl;
  cout<<primero->links.get_head()->value->llegada->dato;
  return 0;
}
