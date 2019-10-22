#include <iostream>
#include "./Screen.hpp"
#include "./Graph.hpp"
using namespace std;

int main()
{
  graph<false,char>* grafo = new graph<false,char>;
  Vertex<char>* primero = new Vertex<char>('a',0,0);
  Vertex<char>* segundo = new Vertex<char>('b',3,4);
  grafo->insert_nodo(primero);
  grafo->insert_nodo(primero);
  grafo->insert_nodo(segundo);
  grafo->insert_nodo(segundo);
  grafo->make_link(primero,segundo);
  cout<<primero->x<<endl;
  cout<<primero->grade() << endl;
  grafo->nodos.sort();
  grafo->nodos.for_each([](Vertex<char> *i){
    cout << i << endl;
    }
  );
  return 0;
}
