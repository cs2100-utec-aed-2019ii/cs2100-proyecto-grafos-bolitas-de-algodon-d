#include <iostream>
#include "./Screen.hpp"
#include "./Graph.hpp"
using namespace std;

int main()
{

  graph<false,char>* grafo = new graph<false,char>;
  Vertex<char> * prim= new Vertex<char>('a',0,0); 
  Vertex<char> * sec= new Vertex<char>('b',0,1);
  Vertex<char> * ter= new Vertex<char>('c',0,2);
  Vertex<char> * cua= new Vertex<char>('d',0,3);
  Vertex<char> * cin= new Vertex<char>('e',0,4);
  grafo->insert_nodo(prim);
  grafo->insert_nodo(sec);
  grafo->insert_nodo(ter);
  grafo->insert_nodo(cua);
  grafo->insert_nodo(cin);
  grafo->make_link(prim,sec);
  grafo->make_link(prim,cua);
  grafo->make_link(sec,ter);
  cout<<grafo->get_neighbort('b').at(0)->data<<endl;
  cout<<grafo->get_neighbort('a').at(1)->data<<endl;
  cout<<grafo->BFS('c')->data<<endl;
  cout<<grafo->DFS('c')->data<<endl;
  cout<<grafo->is_connect();

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
