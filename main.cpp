#include <iostream>
#include "./Glufunc.hpp"
using namespace std;

int main(int argc, char **argv)
{ 
  
  //graph<false,char> grafo;
  //grafo.insert_nodo((float)5.5, 4.0);
  //grafo.insert_nodo((float)5.2, 4.0);
  //grafo.insert_nodo((float)3.5, 4.0);
  //grafo.insert_nodo((float)2.5, 4.0);
  //grafo.insert_nodo((float)7.5, 4.0);
  //grafo.make_link(a,b);
  //grafo.make_link(a,c);
  //grafo.make_link(b,d);
  //grafo.make_link(c,d);
  //grafo.make_link(c,e);
  //grafo.make_link(d,e);
  //grafo.make_link(e,e);
  //cout<<grafo.BFS('e')->data<<endl;
  //cout<<"La densidad del grafo es: "<<grafo.calc_density()<<endl;
  //cout<<"El grado de "<< grafo.DFS('e')->data<<" es "<< grafo.DFS('e')->grade() <<endl;
  //cout<<"Esta conectado: "<<grafo.is_connect()<<endl;
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
