#ifndef ITERATOR
#define ITERATOR
#include "Vertex.hpp"

template<class T>
class Iterator
{
private:
    Vertex<T>* root;
    List<Link<T>*> visitados;
public:
    Iterator(Vertex<T>*& inicializador):root(inicializador){}
    ~Iterator();
    
    Iterator<T>&  operator--(){
        auto menor = root->links.at(0);
        root->links.for_each([this, &menor](Link<T> *i){
            bool existe = false;
            visitados.for_each([i, &existe](Link<T>* visitado){
                if(i==visitado)
                    existe = true;
            });
            if(existe == false)
                menor = menor->peso<i->peso?menor:i;
            
        });
        visitados.push(menor);
        menor.
        return (*this);
    }

    Iterator<T>& operator++(){
        auto mayor = root->links.at(0);
        root->links.for_each([this->visitados,&mayor](Link<T> *i){
            bool existe = false;
            visitados.for_each([i, &existe](Link<T>* visitado){
                if(i==visitado)
                    existe = true;
            });
            if(existe == false)
                mayor = mayor->peso>i->peso?mayor:i;
            
        });
        visitados.push(mayor);
        return (*this);
    }
};
#endif