#include <iostream>
#include "./Glufunc.hpp"
using namespace std;

int main(int argc, char **argv)
{ 
  
  graph<false,char> grafo;
  Vertex<char>* a =new Vertex<char>('a',0,0); 
  Vertex<char>* b =new Vertex<char>('b',3,4);
  Vertex<char>* c =new Vertex<char>('c',0,3);
  Vertex<char>* d =new Vertex<char>('d',0,4);
  Vertex<char>* e =new Vertex<char>('e',0,5); 
  grafo.insert_nodo(a);
  grafo.insert_nodo(b);
  grafo.insert_nodo(c);
  grafo.insert_nodo(d);
  grafo.insert_nodo(e);
  grafo.make_link(a,b);
  grafo.make_link(a,c);
  grafo.make_link(b,d);
  grafo.make_link(c,d);
  grafo.make_link(c,e);
  grafo.make_link(d,e);
  grafo.make_link(e,e);
  cout<<grafo.BFS('e')->data<<endl;
  cout<<"La densidad del grafo es: "<<grafo.calc_density()<<endl;
  cout<<"El grado de "<< grafo.DFS('e')->data<<" es "<< grafo.DFS('e')->grade() <<endl;
  cout<<"Esta conectado: "<<grafo.is_connect()<<endl;
  cout<<grafo.prim('a').BFS('c')->grade()<<endl;
  
 /*value = new Screen<char>(argc, argv, 640, 480, drawHandler, mouseHandler);

  value->Start();
  delete value;
  
  List<int> a;
  a.push(4);
  a.push(2);
  a.push(5);
  a.push(3);
  for(int i = 0; i < a.length(); i++)
  {
    cout << a.at(i) << endl;
  }
  cout << endl;

  a.for_each(
    [](int i){
      cout << i << endl;
    }
  );
*/
  return 0;
}
