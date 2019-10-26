#include <iostream>
#include "./Screen.hpp"
#include "./Graph.hpp"
using namespace std;

int main()
{
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
  List<int> a;
  a.push(3);
  a.push(2);
  a.push(5);
  a.push(9);
  a.push(8);
  a.push(9);
  a.for_each([](int i){
      cout << i << " ";
    }
  );
  cout << endl;
  a.pop_front();
  a.for_each([](int i){
      cout << i << " ";
    }
  );
  cout << endl;
  return 0;
}
