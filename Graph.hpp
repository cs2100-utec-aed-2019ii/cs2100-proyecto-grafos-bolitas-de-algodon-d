#ifndef GRAPH_H
#define GRAPH_H
#include <cmath>
#include "./ForwardList.hpp"
#include "./Vertex.hpp"
#include "./Link.hpp"
#include "./Macros.hpp"

template<typename T>
class writer;

template<typename T>
class Parser;

template<typename T>
class Screen;

template<bool dir, typename T>
class graph;

template<bool dir,typename T>
struct graph_helper 
{
  static void insert(graph<dir, T> *element, float x, float y, T dato = Defaults<T>::value)
  {
    Vertex<T>* nuevo = new Vertex<T>(dato,x,y);
    element->nodos.push(nuevo);
  }
  static void make_link(graph<dir, T> *element, Vertex<T> *nodo_1,Vertex<T> *nodo_2)
  {
    auto x_1 = nodo_1->x;
    auto x_2 = nodo_2->x;
    auto y_1 = nodo_1->y;
    auto y_2 = nodo_2->y;
    float peso = element->calc_distan(x_1,x_2,y_1,y_2);
    Link<T>* nuevolink = new Link<T>(nodo_1,nodo_2,peso);
    nodo_1->links.push(nuevolink);
    nodo_2->links.push(nuevolink);
    element->links.push(nuevolink); 
  }
};

template <bool dir = false, typename T = bool>
class graph
{
public: //Nota mental, poner esto en privado
  List<Vertex<T>*> nodos;
  List<Link<T>*> links;
public:
  graph (){}
  graph (graph &grafo){

  }
  
  virtual ~graph (){
  }

  void insert_nodo(float x,float y,T dato = Defaults<T>::value){
    graph_helper<dir,T>::insert(this, x, y, dato);
  }

  void insert_nodo(T dato,float x = 0,float y = 0){
    graph_helper<dir,T>::insert(this, x, y, dato);
  }
  void make_link(int first, int second)
  {
    make_link(nodos.at(first), nodos.at(second));
  }

  void make_link(Vertex<T> *nodo_1,Vertex<T> *nodo_2){
    graph_helper<dir,T>::make_link(this, nodo_1, nodo_2);
  }

  void rm_link(Vertex<T>*nodo_1,Vertex<T>*nodo_2){
    Link<T>* aux_delete = find_link(nodo_1,nodo_2); 
    delete aux_delete;
  }

  void rm_Vertex(Vertex<T>* nodo){
    Vertex<T>* temp = nullptr;
    nodos.for_each(
      [nodo, temp](Vertex<T> *i){
        if(i == nodo)
        {
          temp = i;
        }
      }
    );
    nodos.pop(temp);
  }

  bool is_connect (){
    
  }
  bool is_bipartited(){

  }
  float calc_density(){
      return (2*links->size)/(nodos->size /nodos->size) ;
  }
  
  graph prim(Vertex<T>* inicial){
    Vertex<T>* temp;
    graph<dir,T>* nuevografo = new graph<dir,T>;
    nodos.for_each(
      [inicial, temp](Vertex<T> *i){
        if(i == inicial)
        {
          temp = i;
        }
      }
    );

  
  }
  graph kruskal(){

  }

//busquedas---------------------------

  Vertex<T> * BFS(){

  }
  Vertex<T> * DFS(){
    
  }

  List <Vertex<T>*> get_neighbort(Vertex<T>* nodo){
      Vertex<T>* temp = nullptr;
      
      nodos->for_each( 
        [temp, nodo](Vertex<T> *i){
        if(i == nodo)
          {
          temp = i;
          }
        }
      );

      List<Vertex<T>*> listaret = new List<Vertex<T>*>;
      Vertex<T>* destiny = nullptr;
      
      temp->links->for_each( [destiny,listaret] (Link<T> *i){
          destiny = i->llegada;    
          listaret->push_back(destiny);
        } 
      );
      return listaret;
  }

  //auxiliares
  float calc_distan(float x1,float x2,float y1,float y2){
    return sqrt( pow((x2-x1),2) + pow((y2-y1),2));
  }
  
  bool exist(T dato){
    //nodos->for_each(nodos->head);
  }

  friend class Screen<T>;
  friend class Parser<T>;
  friend class writer<T>;
  friend class graph_helper<dir,T>;
};

#endif
