#ifndef IT_H
#define IT_H
#include "./ForwardList.hpp"
#include "./Vertex.hpp"
#include "./Macros.hpp"

template<typename T>
class Iterator
{
private:
  Vertex<T> *actual;
  Link<T> *last;
  List<Link<T>*> path;
  void setcolor()
  {
    actual->r = 255;
    actual->g = 0;
    actual->b = 0;
  }
  void setariscolor()
  {
    last->r = 255;
    last->g = 0;
    last->b = 0;
  }
  void invsetcolor()
  {
    actual->r = 255;
    actual->g = 255;
    actual->b = 255;
    last->r = 255;
    last->g = 255;
    last->b = 255;
  }
public:
  Iterator(Vertex<T> *value)
  {
    actual = value;
    last = nullptr;
    setcolor();
  }
  void operator++()
  {
    List<Link<T>*> availables;
    actual->links_de_donde.for_each(
      [&availables, this](Link<T>* i){
        if(path.index(i) == -1)
        {
          availables.push(i);
        }
      }
    );
    actual->links.for_each(
      [&availables, this](Link<T>* i){
        if(path.index(i) == -1)
        {
          availables.push(i);
        }
      }
    );
    if(!availables.length()){return;}
    Link<T> *max = availables.at(0);
    availables.for_each(
      [&max](Link<T> *i){
        if(i->peso > max->peso)
        {
          max = i;
        }
      }
    );
    last = max;
    path.push(last);
    actual = max->llegada;
    setcolor();
    setariscolor();
    glutPostRedisplay();
  }
  void operator--()
  {
    List<Link<T>*> availables;
    actual->links_de_donde.for_each(
      [&availables, this](Link<T>* i){
        if(path.index(i) == -1)
        {
          availables.push(i);
        }
      }
    );
    actual->links.for_each(
      [&availables, this](Link<T>* i){
        if(path.index(i) == -1)
        {
          availables.push(i);
        }
      }
    );
    if(!availables.length()){return;}
    Link<T> *min = availables.at(0);
    availables.for_each(
      [&min](Link<T> *i){
        if(i->peso < min->peso)
        {
          min = i;
        }
      }
    );
    last = min;
    path.push(last);
    actual = min->llegada;
    setcolor();
    setariscolor();
    glutPostRedisplay();
  }
  //void operator--()
  //{
  //  if(!last){return;}
  //  invsetcolor();
  //  actual = last->partida;
  //  path.pop(last);
  //  path.for_each(
  //    [this](Link<T>* i){
  //      actual->links_de_donde.for_each(
  //        [this, i](Link<T> *j){
  //          if(i == j)
  //          {
  //            last = i;
  //          }
  //        }
  //      );
  //      actual->links.for_each(
  //        [this, i](Link<T> *j){
  //          if(i == j)
  //          {
  //            last = i;
  //          }
  //        }
  //      );
  //    }
  //  );
  //  glutPostRedisplay();
  //}
};

#endif
