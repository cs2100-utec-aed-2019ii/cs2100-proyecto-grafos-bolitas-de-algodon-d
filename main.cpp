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
<<<<<<< HEAD
  cout<<primero->links.get_head()->value->llegada->dato << endl;
  cout<<primero->links.get_head()->value->peso<<endl;
=======
  cout<<primero->links.at(0)->llegada->dato;
>>>>>>> e00b49921bfdfc7684ef4cfd513570678dcd24e6
  return 0;
}
