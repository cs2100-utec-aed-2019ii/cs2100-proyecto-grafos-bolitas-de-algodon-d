#include <iostream>
#include "./Glufunc.hpp"
using namespace std;

int main(int argc, char **argv)
{ 
  
  graph<false,char> grafo;
  grafo.insert_nodo((float)1.5, 4.0);
  grafo.insert_nodo((float)2.5, 4.0);
  grafo.insert_nodo((float)3.5, 4.0);
  grafo.insert_nodo((float)4.5, 4.0);
  grafo.make_link(0,1);
  grafo.make_link(1,3);
  grafo.make_link(1,2);
  grafo.make_link(0,3);
  grafo.make_link(2,3);
  auto a = grafo.nodos.at(0);
  auto b = grafo.nodos.at(2);
  cout<<grafo.BFS(a->data)->data<<endl;
  cout<<"La densidad del grafo es: "<<grafo.calc_density()<<endl;
  cout<<"El grado del vertice "<< grafo.DFS(a->data)->data<<" es "<< grafo.DFS(a->data)->grade() <<endl;
  cout<<"Esta conectado: "<<grafo.is_connect()<<endl;
  for(int i = 0; i< grafo.get_neighbort(a->data).length();i++){
    cout<<grafo.get_neighbort(a->data).at(i)->data<<" ";
  }
  cout<<endl<<"Los vertices "<<a->data <<" y "<<b->data <<" son vecinos: "<< grafo.val_neight_threshold(a->data,b->data);
  //cout<<grafo.prim('a').BFS('c')->grade()<<endl;
  

 value = new Screen<char>(argc, argv, 640, 480, drawHandler, mouseHandler, keyboardHandler);


  value->Start();
  delete value;
  
  /*
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
