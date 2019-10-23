#ifndef GRAPH_H
#define GRAPH_H
#include <cmath>
#include "./ForwardList.hpp"
#include "./Vertex.hpp"
#include "./Link.hpp"
#include "./Macros.hpp"

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
};

template <bool dir = false, typename T = bool>
class graph
{
public: //Nota mental, poner esto en privado
  List<Vertex<T>*> nodos;
  List<Link<T>*> links;
public:
  graph (){
    nodos->for_each(
      [](Vertex<T>* i){
        i = nullptr;
      }
    );
    links->for_each(
      [](Link<T>* i){
        i = nullptr;
      }
    );
  }
  graph (graph &grafo){

  }
  
  virtual ~graph (){
  }

  void insert_nodo(Vertex<T>* nodo){
    Vertex<T>* nuevo = new Vertex<T>(nodo->data, nodo->x,nodo->y);
    nodos.push(nuevo);
  }

  void insert_nodo(float x,float y,T dato = Defaults<T>::value){
    graph_helper<dir,T>::insert(this, x, y, dato);
  }

  void insert_nodo(T dato,float x = 0,float y = 0){
    graph_helper<dir,T>::insert(this, x, y, dato);
  }

  void make_link(Vertex<T>*nodo_1,Vertex<T>*nodo_2 ){
    auto x_1 = nodo_1->x;
    auto x_2 = nodo_2->x;
    auto y_1 = nodo_1->y;
    auto y_2 = nodo_2->y;
    float peso = calc_distan(x_1,x_2,y_1,y_2);
    Link<T>* nuevolink = new Link<T>(nodo_1,nodo_2,peso);
    nodo_1->links.push(nuevolink);
    nodo_2->links.push(nuevolink);
    links.push(nuevolink); 
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
    Vertex<T>*aux =  this->nodos->at(0);
      List<Vertex<T>*> cola = new List<Vertex<T>*>;
      List<Vertex<T>*> visitados = new List<Vertex<T>*>;
      //agregar elemento a la cola
      
      while (visitados.length()< nodos.length())
      { 
        visitados.push(aux);
        aux->links->for_each(
        [](Vertex<T> *i){
          if (cola.exist(i)==false)cola.push(i);
          }
        );
        aux = cola->pop_front();
      }
      if(visitados->length()==nodos->length())return true;
      else return false;
  }
  bool is_bipartited(){

  }
  float calc_density(){
      return (2*links->size)/(nodos->size /nodos->size) ;
  }
  
  graph prim(Vertex<T>* inicial){
    Vertex<T>* inicio =  BFS(inicial);// Buscamos? o de frente hacemos el algoritmo?
    Vertex<T>* aux=inicio;
    graph nuevo = new graph;
    //Encontrar minimo arista
    nuevo.insert_nodo(aux);
    float menorp = aux->links.at(0)->peso;
    aux->links->for_each( 
      [menorp](Link<T> *i){
        if(i->peso<=menorp)menorp = i->peso;
      }
    );
    int j = 0;
    links->for_each( 
      [menorp,&j](Link<T> *i){
        if(i->peso==menorp&& j>0){j++;nuevo.insert_nodo(i);} // Traits - falta identificar si hay dos con el mismo peso(comprobación)
      }
    );

//------ ---------------



  
  
  }


  graph kruskal(){ 

  }

//busquedas---------------------------

  Vertex<T> * BFS(Vertex<T>* buscado){
      Vertex<T>*aux =  this->nodos->at(0);
      if(aux == buscado){
        return buscado;
      }
      List<Vertex<T>*> cola = new List<Vertex<T>*>;
      List<Vertex<T>*> visitados = new List<Vertex<T>*>;
      //agregar elemento a la cola
      
      while (visitados.length()< nodos.length())
      { 
        if(aux == buscado) return aux; 
        visitados.push(aux);
        aux->links->for_each(
        [](Vertex<T> *i){
          if (cola.exist(i)==false)cola.push(i); //falta implementar en la lista principal
          }
        );
        aux = cola->pop_front(); //falta implementar en la lista principal
      }
  }


  Vertex<T> * DFS(Vertex<T>* buscado){
      Vertex<T>*aux =  this->nodos->at(0);
      if(aux == buscado){
        return buscado;
      }
      List<Vertex<T>*> cola = new List<Vertex<T>*>;
      List<Vertex<T>*> visitados = new List<Vertex<T>*>;
      //agregar elemento al stack
      
      while (visitados.length()< nodos.length())
      { 
        if(aux == buscado) return aux; 
        visitados.push(aux);
        aux->links->for_each(
        [](Vertex<T> *i){
          if (cola.exist(i)==false)cola.add(i);
          }
        );
        aux = cola->pop_front();
      }
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


  friend class Screen<T>;
  friend class graph_helper<dir,T>;



};

#endif
