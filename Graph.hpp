#ifndef GRAPH_H
#define GRAPH_H
#include "./ForwardList.hpp"
#include "./Vertex.hpp"
#include "./Link.hpp"
#include <string>


template <typename T>
class graph
{
private:
  List<Node<T>*> nodos;
  List<Link<T>*> links ;
  void processvtk(){

    }
public:
  graph (){}
  graph (graph &grafo){

  }
  
  graph(std::string nombre_archivo){

  }

  virtual ~graph (){}

  void insert_nodo(Node<T>* nodo ){

  }

  void make_link(Node<T>*nodo_1,Node<T>*nodo_2 ){

  }
  void rm_link(Node<T>*nodo_1,Node<T>*nodo_2){

  }

  void rm_node(Node<T>* nodo){

  }
  bool is_connect (){

  }
  bool is_bipartited(){

  }
  float calc_density(){

  }
  graph prim(Node<T>* inicial){

  }
  graph kruskal(){

  }

//busquedas---------------------------

  Node<T> * BFS(){

  }
  Node<T> * DFS(){
    
  }

  List <Node<T>*> get_neighbort(){

  }
  

  //auxiliares

    void save(){

    }


};

#endif
