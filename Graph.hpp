#ifndef GRAPH_H
#define GRAPH_H
#include <cmath>
#include "./ForwardList.hpp"
#include "./Vertex.hpp"
#include "./Link.hpp"
#include "./Macros.hpp"

template<typename T>
class Screen;

template <typename T>
class graph
{
private:
  List<Vertex<T>*> nodos;
  List<Link<T>*> links ;
public:
  graph (){}
  graph (graph &grafo){

  }
  
  virtual ~graph (){
    delete nodos;
    delete links;
  }

  void insert_nodo(Vertex<T>* nodo,List<Link<T>>aristas){
    Vertex<T>* nuevo = new Vertex<T>(nodo->dato,nodo->x,nodo->y);
    nodos.push(nuevo);
  }

  void make_link(Vertex<T>*nodo_1,Vertex<T>*nodo_2 ){
    auto x_1 = nodo_1->x;
    auto x_2 = nodo_2->x;
    auto y_1 = nodo_1->y;
    auto y_2 = nodo_2->y;
    float peso = calc_distan(x_1,x_2,y_1,y_2);
    Link<T>* nuevolink = new Link<T>(nodo_1,nodo_2,peso);
    nodo_1->links->push(nuevolink);
    nodo_2->links->push(nuevolink);
  }
  void rm_link(Vertex<T>*nodo_1,Vertex<T>*nodo_2){
    
    Link<T>* aux_delete = find_link(nodo_1,nodo_2); //creo que debemos implementar un find en la lista principal, mn
    //el find link esta por implementarse recién

    //para borrar de la lista de cada nodo tmbn debe ser util un find in lista :v
    delete aux_delete;
  }

  void rm_Vertex(Vertex<T>* nodo){

  }
  bool is_connect (){

  }
  bool is_bipartited(){

  }
  float calc_density(){

  }
  graph prim(Vertex<T>* inicial){

  }
  graph kruskal(){

  }

//busquedas---------------------------

  Vertex<T> * BFS(){

  }
  Vertex<T> * DFS(){
    
  }

  List <Vertex<T>*> get_neighbort(){

  }

  //auxiliares
  float calc_distan(float x1,float x2,float y1,float y2){
    return sqrt( pow((x2-x1),2) + pow((y2-y1),2));
  }
  
  bool exist(T dato){

  }

  void save(){

  }

  friend class Screen<T>;
};

#endif
