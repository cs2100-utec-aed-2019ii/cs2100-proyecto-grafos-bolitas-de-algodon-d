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
  static void make_link(graph<dir, T> *element, Vertex<T> *nodo_1,Vertex<T> *nodo_2)
  {
    if(nodo_1 == nodo_2) {
      cout<<"no se pueden hacer ciclos, arista eliminado de "<<nodo_1->data<<" a "<<nodo_1->data<<endl;
      
      return;
    }
    auto x_1 = nodo_1->x;
    auto x_2 = nodo_2->x;
    auto y_1 = nodo_1->y;
    auto y_2 = nodo_2->y;
    float peso = element->calc_distan(x_1,x_2,y_1,y_2);
    Link<T>* nuevolink = new Link<T>(nodo_1,nodo_2,peso);
    nodo_1->links.push(nuevolink);
    nodo_2->links_de_donde.push(nuevolink);//dirigido no dirigido diferencia
    element->links.push(nuevolink); 
  }
  static void del(graph<dir, T>* value, Vertex<T> *val)
  {
  }
};

template<typename T>
struct graph_helper<true,T> 
{
  static void make_link(graph<true, T> *element, Vertex<T> *nodo_1,Vertex<T> *nodo_2)
  {
    if(nodo_1 == nodo_2) {
      cout<<"no se pueden hacer ciclos, arista eliminado de "<<nodo_1->data<<" a "<<nodo_1->data<<endl;
      return;
    }
    auto x_1 = nodo_1->x;
    auto x_2 = nodo_2->x;
    auto y_1 = nodo_1->y;
    auto y_2 = nodo_2->y;
    float peso = element->calc_distan(x_1,x_2,y_1,y_2);
    Link<T>* nuevolink = new Link<T>(nodo_1,nodo_2,peso);
    nodo_1->links.push(nuevolink);
    element->links.push(nuevolink); 
  }
};

template <bool dir = false, typename T = unsigned int>
class graph
{
private: 
  List<Vertex<T>*> nodos;
  List<Link<T>*> links;
  float max_x;
  float max_y;
public:

  graph (): max_x(0), max_y(0){}
  graph (graph &grafo): max_x(0), max_y(0){
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

  void insert_nodo(float x,float y,T dato = Defaults<T>::get_value()){
    Vertex<T>* nuevo = new Vertex<T>(dato,x,y);
    if(max_x < x){max_x = nuevo->x;}
    if(max_y < y){max_y = nuevo->y;}
    nodos.push(nuevo);
  }

  void insert_nodo(T dato,float x = 0,float y = 0){
    Vertex<T>* nuevo = new Vertex<T>(dato,x,y);
    if(max_x < x){max_x = nuevo->x;}
    if(max_y < y){max_y = nuevo->y;}
    nodos.push(nuevo);
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
    //Link<T>* aux_delete = find_link(nodo_1,nodo_2); 
    //delete aux_delete;
  }

  void rm_Vertex(T dato){
    Vertex<T>* temp = BFS(dato);
    nodos.pop(temp);
  }

  bool is_connect (){
      Vertex<T>*aux =  nodos.at(0);
      List<Vertex<T>*> cola ;
      List<Vertex<T>*> visitados ;
      visitados.push(aux);
      while ( visitados.length()< nodos.length())
      {   
          
          if(aux->links.length()!=0){
          for (int i = 0; i < aux->links.length(); i++)
            {   
              if(cola.index(aux->links.at(i)->llegada)==-1 && visitados.index(aux->links.at(i)->llegada)==-1){
                cola.push(aux->links.at(i)->llegada);
              }
            }
          }    
          visitados.push(aux);
          aux = cola.pop_front();
          if(cola.length()==0)break;
      }
      if(visitados.length()==nodos.length())return true;
      else return false;
  }

  bool is_bipartited(){

  }
  float calc_density(){
      return ((float) 2*links.length()) / (float)((nodos.length() *(nodos.length()-1))) ;
  }
  
  graph<false,T> prim(T inicial){
    Vertex<T>* aux =  BFS(inicial);
    List<Link<T>*> a_disponi;
    graph nuevo;
    
    if(is_connect()){
        while(nuevo.nodos.length()<nodos.length()){
          
           if(nuevo.nodos.index(aux)==-1){ 
             for (int i = 0; i<aux->links.length() ; i++)
             {
                if(nuevo.links.index(aux->links.at(i))==-1) {
                   a_disponi.push(aux->links.at(i));
                }
             }
            for (int i = 0; i < a_disponi.length(); i++)
            {
              cout<<a_disponi.at(i)->peso<<endl;
            }
           Vertex<T>* lle_min = nullptr;
           for (int i = 0; i < a_disponi.length(); i++)
           {  
                Link<T>*llelinkmin = min(a_disponi);
              if(nuevo.nodos.index(llelinkmin->llegada)==-1) {
                 lle_min= llelinkmin->llegada;
                 break;
                } 
           }    
             
///--------------
        //asignacion

            nuevo.insert_nodo(aux);
            nuevo.insert_nodo(lle_min);

            
            nuevo.make_link(aux,lle_min);
            aux = lle_min;
           }
        } return nuevo;
    }
    //else return nullptr;
  }


  Link<T>* min(List<Link<T>*> & lista){
    
    Link<T>* menorp = lista.at(0);
    for (int i = 0; i < lista.length(); i++)
    {
      if(menorp->peso > lista.at(i)->peso ) menorp = lista.at(i); 
    }
    Link<T>* res = menorp;
    lista.pop(menorp); 
    return res;
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
