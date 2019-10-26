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
   // nodo_2->links.push(nuevolink);//dirigido no dirigido diferencia
    element->links.push(nuevolink); 
  }
};

template <bool dir = false, typename T = unsigned char>
class graph
{
private: 
  List<Vertex<T>*> nodos;
  List<Link<T>*> links;
public:
  graph (){
    for (int i = 0; i < nodos.length(); i++)
    {
      nodos.at(i)=nullptr;
    }
    for (int i = 0; i < links.length(); i++)
    {
      links.at(i)=nullptr;
    }
    
  }
  graph (graph &grafo){

  }
  
  virtual ~graph (){
    nodos.for_each(
      [](Vertex<T> *i){
        delete i;
      }
    );
    links.for_each(
      [](Link<T> *i){
        delete i;
      }
    );
  }

  void insert_nodo(float x,float y,T dato = Defaults<T>::value){
    graph_helper<dir,T>::insert(this, x, y, dato);
  }

  void insert_nodo(T dato,float x = 0,float y = 0){
    graph_helper<dir,T>::insert(this, x, y, dato);
  }

  //--------------
  void insert_nodo(Vertex<T>* nodo){
    nodos.push(nodo);
  }
  //---------------

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
      Vertex<T>*aux =  nodos.at(0);
      List<Vertex<T>*> cola ;
      List<Vertex<T>*> visitados ;
      
      while ( visitados.length()< nodos.length())
      {   
          visitados.push(aux);
          if(aux->links.length()!=0){
          for (int i = 0; i < aux->links.length(); i++)
            {   
              if(cola.index(aux->links.at(i)->llegada)==-1 && visitados.index(aux->links.at(i)->llegada)==-1){
                cola.push(aux->links.at(i)->llegada);
              }
            }
          }    
          aux = cola.pop_front();
          if(cola.length()==0)break;
      }
      if(visitados.length()==nodos.length())return true;
      else return false;
  }

  bool is_bipartited(){

  }
  float calc_density(){
      return (2*links->size)/(nodos->size /nodos->size) ;
  }
  
  graph prim(T inicial){
    Vertex<T>* inicio =  BFS(inicial);// Buscamos? o de frente hacemos el algoritmo?
    Vertex<T>* aux=inicio;
    List<Link<T>*> estruc;
    graph nuevo = new graph;
    //Encontrar minimo arista
    nuevo.insert_nodo(aux);
    float menorp = aux->links.at(0)->peso;
    aux->links.for_each( 
      [menorp](Link<T> *i){
        if(i->peso<=menorp)menorp = i->peso;
      }
    );
    int j = 0; 
    aux->links.for_each( 
      [menorp,&j](Link<T> *i){
        if(i->peso==menorp&& j>0){j++;nuevo.insert_nodo(i->llegada);
          nuevo.make_link();
         } 
      }
    );
  }


  graph kruskal(){ 

  }

//busquedas---------------------------

  Vertex<T> * BFS( T buscadob){
      Vertex<T>*aux = nodos.at(0);
      if(aux->data == buscadob){
        return aux;
      }
      List<Vertex<T>*>cola ;
      List<Vertex<T>*>visitados ;
      while ( visitados.length()< nodos.length())
      { 
        if(aux->data == buscadob) return aux; 
        else{  
          visitados.push(aux);
          if(aux->links.length()!=0){
          for (int i = 0; i < aux->links.length(); i++)
            {   
              if(cola.index(aux->links.at(i)->llegada)==-1 && visitados.index(aux->links.at(i)->llegada)==-1){
                cola.push(aux->links.at(i)->llegada);
              }
            }
          }
          
          aux = cola.pop_front();
        }  
      }
      
      return nullptr;
  }

  


  Vertex<T> * DFS(T buscadob){
      Vertex<T>*aux = nodos.at(0);
      if(aux->data == buscadob){
        return aux;
      }
      List<Vertex<T>*>cola ;
      List<Vertex<T>*>visitados ;
      while ( visitados.length()< nodos.length())
      { 
        if(aux->data == buscadob) return aux; 
        else{  
          visitados.push(aux);
          if(aux->links.length()!=0){
          for (int i = 0; i < aux->links.length(); i++)
            {   
              if(cola.index(aux->links.at(i)->llegada)==-1 && visitados.index(aux->links.at(i)->llegada)==-1){
                cola.add(aux->links.at(i)->llegada);
              }
            }
          }
          
          aux = cola.pop_front();
        }  
      }  
      return nullptr;
  }

  List <Vertex<T>*> get_neighbort(T dato){
      Vertex<T>* temp = nullptr;
      
      temp = BFS(dato); // Uso de BFS para buscar nodos
      
      List<Vertex<T>*> listaret;
      Vertex<T>* destiny = nullptr;
      
      for (unsigned int i = 0; i < temp->links.length(); i++)
      {
        destiny = temp->links.at(i)->llegada;
        listaret.push(destiny);
      }
      return listaret;
  }

  //auxiliares
  float calc_distan(float x1,float x2,float y1,float y2){
    return sqrt( pow((x2-x1),2) + pow((y2-y1),2));
  }


  friend class Screen<T>;
  friend class Parser<T>;
  friend class writer<T>;
  friend class graph_helper<dir,T>;



};

#endif
